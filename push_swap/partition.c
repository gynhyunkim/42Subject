/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:44:08 by gkim              #+#    #+#             */
/*   Updated: 2021/11/20 22:36:58 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	rewind(t_obj *o, int ra, int rb)
{
	while (ra && rb)
	{
		reverse_rotate(o, 2);
		ra--;
		rb--;
	}
	while (ra--)
		reverse_rotate(o, 0);
	while (rb--)
		reverse_rotate(o, 1);
}

static void	a_partition(t_obj *o, int *pivt, int r, int *rnum)
{
	rnum[0] = 0;
	rnum[1] = 0;
	while (r--)
	{
		if (o->stack[0]->head->next->data >= pivt[1])
			rnum[0] += rotate(o, 0);
		else
		{
			push(o, 1);
			if (o->stack[1]->head->next->data >= pivt[0])
				rnum[1] += rotate(o, 1);
		}
	}
}

void	a_to_b(t_obj *o, int *sorted, int l, int r)
{
	int	rnum[2];
	int	pivot[2];

	if (r - l < 4)
	{
		sort(o, 0);
		return ;
	}
	pivot[0] = sorted[l + (r - l) / 3];
	pivot[1] = sorted[l + (r - l) / 3 * 2];
	a_partition(o, pivot, r - l, rnum);
	rewind(o, rnum[0], rnum[1]);
	a_to_b(o, sorted, l + (r - l) / 3 * 2, r);
	b_to_a(o, sorted, l + (r - l) / 3, l + (r - l) / 3 * 2);
	b_to_a(o, sorted, l, l + (r - l) / 3);
}

void	b_partition(t_obj *o, int *pivt, int r, int *rnum)
{
	rnum[0] = 0;
	rnum[1] = 0;
	while (r--)
	{
		if (o->stack[1]->head->next->data < pivt[0])
			rnum[1] += rotate(o, 1);
		else
		{
			push(o, 0);
			if (o->stack[0]->head->next->data < pivt[1])
				rnum[0] += rotate(o, 0);
		}
	}
}

void	b_to_a(t_obj *o, int *sorted, int l, int r)
{
	int	rnum[2];
	int	pivot[2];

	if (r - l < 4)
	{
		sort_r(o, 1);
		while (l++ < r)
			push(o, 0);
		return ;
	}
	pivot[0] = sorted[l + (r - l) / 3];
	pivot[1] = sorted[l + (r - l) / 3 * 2];
	b_partition(o, pivot, r - l, rnum);
	a_to_b(o, sorted, l + (r - l) / 3 * 2, r);
	rewind(o, rnum[0], rnum[1]);
	a_to_b(o, sorted, l + (r - l) / 3, l + (r - l) / 3 * 2);
	b_to_a(o, sorted, l, l + (r - l) / 3);
}
