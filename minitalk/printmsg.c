/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:26:44 by gkim              #+#    #+#             */
/*   Updated: 2021/10/04 11:57:45 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_msg(int pid, char *str, int len)
{
	write(1, "messge : [ ", 12);
	write(1, str, len);
	ft_putstr_fd(" ]\n", 0);
}

void	print_err(char *msg, int pid)
{
	ft_putstr_fd(msg, 1);
	kill(pid, SIGUSR2);
}
