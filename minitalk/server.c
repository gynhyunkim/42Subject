/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:42:34 by gkim              #+#    #+#             */
/*   Updated: 2021/10/03 18:00:11 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_msg	g_msg;

static void	set_sigaction(int idx)
{
	if (sigaction(SIGUSR1, &g_msg.sa[idx], 0)
		|| sigaction(SIGUSR2, &g_msg.sa[idx], 0))
		ft_putstr_fd("sigaction error!\n", 2);
}

static void	init_msg(void)
{
	g_msg.buf = 0;
	g_msg.bit_cnt = 0;
	g_msg.msg_idx = 0;
	g_msg.msg_len = 0;
	g_msg.cur_pid = 0;
	if (!g_msg.msg_buf)
		free(g_msg.msg_buf);
	set_sigaction(0);
}

void	sa_message(int signo, siginfo_t *info, void *old)
{
	if (g_msg.cur_pid != info->si_pid)
	{
		print_err(info->si_pid);
		init_msg();
	}
	else
	{
		kill(info->si_pid, SIGUSR1);
		g_msg.bit_cnt++;
		g_msg.buf = (g_msg.buf << 1) | (signo == SIGUSR2);
		if (g_msg.bit_cnt == 8)
		{
			g_msg.msg_buf[g_msg.msg_idx++] = g_msg.buf;
			if (g_msg.msg_idx == g_msg.msg_len)
			{
				kill(info->si_pid, SIGUSR2);
				print_msg(info->si_pid, g_msg.msg_buf, g_msg.msg_len);
				init_msg();
			}	
			g_msg.buf = 0;
			g_msg.bit_cnt = 0;
		}
	}
}

void	sa_length(int signo, siginfo_t *info, void *uncontext)
{
	if (g_msg.cur_pid == 0)
		g_msg.cur_pid = info->si_pid;
	if (g_msg.cur_pid != info->si_pid)
	{
		print_err(info->si_pid);
		init_msg();
	}
	else
	{
		kill(info->si_pid, SIGUSR1);
		g_msg.bit_cnt++;
		g_msg.msg_len = (g_msg.msg_len << 1) | (signo == SIGUSR2);
		if (g_msg.bit_cnt == 32)
		{
			ft_putstr_fd("len : ", 1);
			ft_putnbr_fd(g_msg.msg_len, 1);
			g_msg.bit_cnt = 0;
			g_msg.msg_buf = (char *)malloc(g_msg.msg_len);
			set_sigaction(1);
		}
	}	
}

int	main(void)
{	
	g_msg.sa[0].sa_sigaction = sa_length;
	g_msg.sa[0].sa_flags = SA_SIGINFO;
	g_msg.sa[1].sa_sigaction = sa_message;
	g_msg.sa[1].sa_flags = SA_SIGINFO;
	set_sigaction(0);
	ft_putstr_fd("server pid : ", 0);
	ft_putnbr_fd(getpid(), 0);
	init_msg();
	while (1)
	{
		pause();
	}
}
