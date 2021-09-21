/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:42:34 by gkim              #+#    #+#             */
/*   Updated: 2021/08/17 16:43:04 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_msg	g_msg;

void	init_msg()
{
	g_msg.buf = 0;
	g_msg.bit_cnt = 0;
	g_msg.msg_list = ft_lstnew(0);
}

void	print_msg()
{
	t_list	*msg;

	msg = g_msg.msg_list->next;
	ft_putstr_fd("received message : [ ", 0);
	while(msg)
	{
		ft_putchar_fd(msg->content, 0);
		msg = msg->next;
	}
	ft_putstr_fd(" ]\n", 0);
}

void	sig_handler(int signo)
{
	g_msg.bit_cnt++;
	g_msg.buf = (g_msg.buf << 1) | (signo == SIGUSR2);
	usleep(50);
	if (g_msg.bit_cnt == 8)
	{
		ft_lstlast(g_msg.msg_list)->next = ft_lstnew(g_msg.buf);
		if (g_msg.buf == 0) {
			print_msg();
			init_msg();
		}
		g_msg.buf = 0;
		g_msg.bit_cnt = 0;
	}
}

int main()
{
	init_msg();
	ft_putstr_fd("server pid : ", 0);
	ft_putnbr_fd(getpid(), 0);
	if (signal(SIGUSR1, sig_handler) == SIG_ERR ||
		signal(SIGUSR2, sig_handler) == SIG_ERR)
		ft_putstr_fd("ERROR!", 2);
	while (1)
	{
		pause();
	}
}