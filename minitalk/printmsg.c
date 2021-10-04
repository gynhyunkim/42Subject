/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:26:44 by gkim              #+#    #+#             */
/*   Updated: 2021/10/04 22:47:26 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_msg(int pid, char *str)
{
	ft_putstr_fd("client pid : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("message : [ ",1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(" ]\n", 1);
}
