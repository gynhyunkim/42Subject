/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:37:11 by gkim              #+#    #+#             */
/*   Updated: 2021/11/21 00:00:30 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	print_cmd(int cmd)
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

static int	check_comb(t_node *node, t_node *next, int a, int b)
{
	if (node->data == a && next->data == b)
		return (1);
	else if (node->data == b && next->data == a)
		return (1);
	return (0);
}

static int	combine_cmd(t_node *node, t_node *next)
{
	if (check_comb(node, next, 1, 2))
	{
		ft_putstr_fd("ss\n", 1);
		return (1);
	}
	else if (check_comb(node, next, 5, 6))
	{
		ft_putstr_fd("rr\n", 1);
		return (1);
	}
	else if (check_comb(node, next, 7, 8))
	{
		ft_putstr_fd("rrr\n", 1);
		return (1);
	}
	else if (check_comb(node, next, 5, 7) || check_comb(node, next, 6, 8))
		return (1);
	return (0);
}

void	cmd_parsing(t_stack *cmd)
{
	t_node	*node;
	t_node	*next;

	node = cmd->head->next;
	while (node->next)
	{
		next = node->next;
		if (combine_cmd(node, next))
			node = next->next;
		else if (check_comb(node, next, 3, 4)
			&& (node->data == next->next->data))
			node = next->next->next;
		else if ((node->data == 1 || node->data == 2)
			&& (node->data == next->data))
			node = next->next->next;
		else
		{
			print_cmd(node->data);
			node = next;
			if (!next->next)
				print_cmd(next->data);
		}
	}
}
