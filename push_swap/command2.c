/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:28:08 by gkim              #+#    #+#             */
/*   Updated: 2021/06/17 22:16:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_obj *o, int key)
{
	t_dlist	*node;

	node = o->stack[key]->head->next;
	
}

void	quick_sort_stack(t_obj *o, int p, int r, int **sorted)
{
	int		pivot1, pivot2, ra;
	t_dlist	*node;

	if (r - p <= 3)
	{
		// sort(o, 0);
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