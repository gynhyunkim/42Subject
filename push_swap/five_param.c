/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:33:20 by gkim              #+#    #+#             */
/*   Updated: 2021/11/20 22:18:30 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	find_min(t_obj *o)
{
	int		i;
	int		min;
	int		min_idx;
	t_node	*node;

	node = o->stack[0]->head->next;
	min = node->data;
	min_idx = 0;
	i = 1;
	while (node->next->next)
	{
		node = node->next;
		if (min > node->data)
		{
			min = node->data;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

static void	push_minimum(t_obj *o)
{
	int	cnt;
	int	idx;

	cnt = 2;
	while (cnt--)
	{
		idx = find_min(o);
		if (idx < o->stack[0]->size / 2)
		{
			while (idx--)
				rotate(o, 0);
		}
		else
		{
			while (idx++ < o->stack[0]->size)
				reverse_rotate(o, 0);
		}
		push(o, 1);
	}
}

void	five_param(t_obj *o)
{
	int		i;
	t_stack	*s;

	push_minimum(o);
	three_sort(o, 0);
	i = 2;
	s = o->stack[0];
	while (i--)
		push(o, 0);
	sort(o, 0);
}
