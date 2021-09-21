/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:28:08 by gkim              #+#    #+#             */
/*   Updated: 2021/07/09 16:55:09 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_obj *o, int key)
{
	t_node	*n1, *n2, *n3;

	n1 = o->stack[key]->head->next;
	n2 = n1->next;
	n3 = n2->next;

	if (n1->data > n2->data)
	{
		if (n1->data > n3->data)
			rotate(o, key);
		if (n2->data > n3->data || n1->data < n3->data)
			swap(o, key);
	}
	else
	{
		if (n2->data > n3->data)
			reverse_rotate(o, key);
		if (n3->data > n1->data)
			swap(o, key);
	}
}

void	five_param(t_obj *o)
{
	int	i;

	for (i = 0; i < 2; i++)
	{
		push(o, 0);
		push(o, 0);
		sort(o, 0);
		push(o, 1);
		if (o->stack[0]->head->next->data > o->stack[0]->head->next->next->data)
		{
			if (o->stack[0]->head->next->data - o->stack[0]->head->next->next->data == 1)
				swap(o, 0);
			else
				rotate(o, 0); 
		}
		push(o, 1);
		if (o->stack[0]->head->next->data > o->stack[0]->head->next->next->data)
		{
			if (o->stack[0]->head->next->data - o->stack[0]->head->next->next->data == 1)
				swap(o, 0);
			else
				rotate(o, 0); 
		}
	}
}

void	quick_sort_stack(t_obj *o, int p, int r, int **sorted)
{
	int		pivot1, pivot2, ra;
	t_node	*node;

	if (r - p <= 3)
	{
		sort(o, 0);
		return ;	
	}
	if (p < r)
	{
		pivot1 = sorted[0][((r + p - 1) / 3) * 2];
		pivot2 = sorted[0][(r + p - 1) / 3];
		printf("pivot1 = %d, pivot2 = %d\n", pivot1, pivot2);
		ra = 0;
		while (p < r)
		{
			node = o->stack[0]->head->next;
			if (node->data > pivot1)
				ra += rotate(o, 0);
			else
			{
				push(o, 0);
				node = o->stack[1]->head->next;
				if (node->data < pivot2)
					rotate(o, 1);
			}
			p++;
		}
		printf("%d %d\n", o->stack[0]->size, o->stack[1]->size);
		while (ra--)
			reverse_rotate(o, 0);
		quick_sort_stack(o, r - o->stack[0]->size, r, sorted);
	}

}