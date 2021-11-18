/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:37:11 by gkim              #+#    #+#             */
/*   Updated: 2021/11/09 20:10:11 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	print_cmd(int cmd)
{
	if (cmd == 1)
		ft_putstr_fd("sa\n", 1);
	else if (cmd == 2)
		ft_putstr_fd("sb\n", 1);
	else if (cmd == 3)
		ft_putstr_fd("pa\n", 1);
	else if (cmd == 4)
		ft_putstr_fd("pb\n", 1);
	else if (cmd == 5)
		ft_putstr_fd("ra\n", 1);
	else if (cmd == 6)
		ft_putstr_fd("rb\n", 1);
	else if (cmd == 7)
		ft_putstr_fd("rra\n", 1);
	else if (cmd == 8)
		ft_putstr_fd("rrb\n", 1);
}

int	cmd_parsing(t_stack *cmd)
{
	int		cnt;
	t_node	*node, *next;

	cnt = 0;
	node = cmd->head->next;
	while (node->next)
	{
		next = node->next;
		if ((node->data == 1 && next->data == 2) || (node->data == 2 && next->data == 1))
		{
			ft_putstr_fd("ss\n", 1);
			node = next->next;
		}
		else if ((node->data == 5 && next->data == 6) || (node->data == 6 && next->data == 5))
		{
			ft_putstr_fd("rr\n", 1);
			node = next->next;
		}
		else if ((node->data == 7 && next->data == 8) || (node->data == 8 && next->data == 7))
		{
			ft_putstr_fd("rrr\n", 1);
			node = next->next;
		}
		else
		{
			print_cmd(node->data);
			node = next;
			if (!next->next)
				print_cmd(next->data);
		}
		cnt++;
	}
	return (cnt);
}