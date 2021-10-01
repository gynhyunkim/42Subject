/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:42:34 by gkim              #+#    #+#             */
/*   Updated: 2021/10/02 02:54:38 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

t_msg	g_msg;
struct sigaction new_act;
struct sigaction new_act2;

void	init_msg(void)
{
	g_msg.buf = 0;
	g_msg.bit_cnt = 0;
	g_msg.msg_idx = 0;
	g_msg.msg_len = 0;
	if (!g_msg.msg_buf)
		free(g_msg.msg_buf);
}

void	print_msg(int pid, int is_end)
{
	write(1, "messge : [ ", 12);
	write(1, g_msg.msg_buf, g_msg.msg_len);
	ft_putstr_fd(" ]\n", 0);
	init_msg();
	kill(pid, SIGUSR1);
	sigaction(SIGUSR1, &new_act, 0);
	sigaction(SIGUSR2, &new_act, 0);
}

void	sig_handler2(int signo, siginfo_t *info, void *old)
{
	g_msg.bit_cnt++;
	g_msg.buf = (g_msg.buf << 1) | (signo == SIGUSR2);
	if (g_msg.bit_cnt == 8)
	{
		g_msg.msg_buf[g_msg.msg_idx++] = g_msg.buf;
		if (g_msg.msg_idx == g_msg.msg_len)
			print_msg(info->si_pid, 0);
		g_msg.buf = 0;
		g_msg.bit_cnt = 0;
	}
}

void	sig_handler(int signo, siginfo_t *info, void *uncontext)
{
	g_msg.bit_cnt++;
	g_msg.msg_len = (g_msg.msg_len << 1) | (signo == SIGUSR2);
	if (g_msg.bit_cnt == 32)
	{
		ft_putstr_fd("len : ", 1);
		ft_putnbr_fd(g_msg.msg_len, 1);
		g_msg.bit_cnt = 0;
		sigaction(SIGUSR1, &new_act2, 0);
		sigaction(SIGUSR2, &new_act2, 0);
		g_msg.msg_buf = (char *)malloc(g_msg.msg_len);
		usleep(100);
		kill(info->si_pid, SIGUSR1);
	}
}	

int	main(void)
{	
	ft_putstr_fd("server pid : ", 0);
	ft_putnbr_fd(getpid(), 0);
	init_msg();

	new_act.sa_sigaction = sig_handler;
	new_act.sa_flags = SA_SIGINFO;

	new_act2.sa_sigaction = sig_handler2;
	new_act2.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &new_act, 0) == -1
		|| sigaction(SIGUSR2, &new_act, 0) == -1)
		ft_putstr_fd("ERROR!", 2);
	
	while (1) ;
}
