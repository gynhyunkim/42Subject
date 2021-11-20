/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:28:08 by gkim              #+#    #+#             */
/*   Updated: 2021/11/20 22:47:58 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	three_sort(t_obj *o, int key)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = o->stack[key]->head->next->data;
	n2 = o->stack[key]->head->next->next->data;
	n3 = o->stack[key]->head->next->next->next->data;
	if (n1 > n2 && n1 < n3)
		swap(o, key);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		reverse_rotate(o, key);
		swap(o, key);
	}
	else if (n1 < n2 && n3 < n2)
		reverse_rotate(o, key);
	else if (n1 > n2 && n2 > n3)
	{
		swap(o, key);
		reverse_rotate(o, key);
	}
	else if (n1 > n2 && n1 > n3)
		rotate(o, 0);
}

static void	two_param(t_obj *o, int key, int reverse)
{
	t_node	*node;

	node = o->stack[key]->head->next;
	if (!reverse && node->data > node->next->data)
		swap(o, key);
	else if (reverse && node->data < node->next->data)
		swap(o, key);
}

void	sort(t_obj *o, int key)
{
	int	data[3];

	data[0] = o->stack[key]->head->next->data;
	data[1] = o->stack[key]->head->next->next->data;
	if (o->stack[key]->size < 3)
		return (two_param(o, key, 0));
	data[2] = o->stack[key]->head->next->next->next->data;
	if (data[0] > data[1] && data[0] < data[2])
		swap(o, key);
	else if (data[0] < data[1] && data[2] < data[1])
	{
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
	else if (data[0] > data[1] && data[0] > data[2])
	{
		swap(o, key);
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
	if (!(data[0] < data[1] && data[1] < data[2]))
		sort(o, key);
}

void	sort_r(t_obj *o, int key)
{
	int	data[3];

	data[0] = o->stack[key]->head->next->data;
	data[1] = o->stack[key]->head->next->next->data;
	if (o->stack[key]->size < 3)
		return (two_param(o, key, 1));
	data[2] = o->stack[key]->head->next->next->next->data;
	if (data[1] > data[0] && data[0] > data[2])
		swap(o, key);
	else if (data[0] > data[1] && data[1] < data[2])
	{
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
	else if (data[0] < data[1] && data[0] < data[2])
	{
		swap(o, key);
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
	if (!(data[0] > data[1] && data[1] > data[2]))
		sort_r(o, key);
}
