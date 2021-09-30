/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:42:34 by gkim              #+#    #+#             */
/*   Updated: 2021/09/30 18:35:09 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_msg	g_msg;

void	init_msg(void)
{
	g_msg.buf = 0;
	g_msg.bit_cnt = 0;
	g_msg.msg_list = ft_lstnew(0);
}

void	free_list(t_list *list)
{
	t_list	*next;
	
	while (list)
	{
		// write(1, "c", 1);
		next = list->next;
		free(list);
		list = next;
	}
}

void	print_msg(void)
{
	t_list	*msg;

	msg = g_msg.msg_list->next;
	ft_putstr_fd("received message : [ ", 0);
	while (msg)
	{
		ft_putchar_fd(msg->content, 0);
		msg = msg->next;
	}
	ft_putstr_fd(" ]\n", 0);
	free_list(g_msg.msg_list);
	init_msg();
}

void	sig_handler(int signo)
{
	t_list	*new_list;

	g_msg.bit_cnt++;
	// ft_putnbr_fd(g_msg.bit_cnt, 1);
	g_msg.buf = (g_msg.buf << 1) | (signo == SIGUSR2);
	if (g_msg.bit_cnt == 8)
	{
		new_list = ft_lstnew(g_msg.buf);
		if (!new_list)
			ft_putstr_fd("malloc error!", 2);
		ft_lstlast(g_msg.msg_list)->next = new_list;
		if (g_msg.buf == 127)
			print_msg();
		g_msg.buf = 0;
		g_msg.bit_cnt = 0;
	}
}

int	main(void)
{
	init_msg();
	ft_putstr_fd("server pid : ", 0);
	ft_putnbr_fd(getpid(), 0);
	if (signal(SIGUSR1, sig_handler) == SIG_ERR
		|| signal(SIGUSR2, sig_handler) == SIG_ERR)
		ft_putstr_fd("ERROR!", 2);
	while (1)
	{
		pause();
	}
}
