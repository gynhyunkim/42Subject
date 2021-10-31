/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:28:08 by gkim              #+#    #+#             */
/*   Updated: 2021/10/29 18:25:20 by gkim             ###   ########.fr       */
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

void	b_to_a(t_obj *o, int l, int r, int **sorted)
{
	int		i, p1, p2, rb_cnt, ra_cnt;
	t_node	*node;

	if (r - l <= 3)
	{
		sort(o, 1);
		while (r-- > l)
			push(o, 1);
		return ;
	}
	p1 = sorted[0][((r + l - 1) / 3) * 2];
	p2 = sorted[0][(r + l - 1) / 3];

	rb_cnt = 0;
	ra_cnt = 0;	
	i = l;	
	while (i++ < r)
	{
		node = o->stack[1]->head->next;
		if (node->data < p2)
		{
			rotate(o, 1);
			rb_cnt++;
		}
		else
		{
			push(o, 1);
			if (o->stack[0]->head->next->data < p1)
			{
				rotate(o, 0);
				ra_cnt++;
			}
		}
	}
	a_to_b(o, p2, r, sorted);
	i = 0;
	while (i < ra_cnt || i < rb_cnt)
	{
		if (i < ra_cnt && i < rb_cnt)
			reverse_rotate(o, 2);
		else if (i < ra_cnt)
			reverse_rotate(o, 0);
		else
			reverse_rotate(o, 1);
		i++;
	}
	a_to_b(o, p2, p1, sorted);
	b_to_a(o, l, p1, sorted);
}

void	a_to_b(t_obj *o, int l, int r, int **sorted)
{
	int		i, p1, p2, cnt[4] = { 0 };
	t_node	*node;

	if (r - l <= 3)
	{
		sort(o, 0);
		return ;
	}
	p1 = sorted[0][((r + l - 1) / 3)];
	p2 = sorted[0][(r + l - 1) / 3 * 2];

	i = l;
	while (i++ < r)
	{
		node = o->stack[0]->head->next;
		if (node->data >= p2)
		{
			rotate(o, 0);
			cnt[0]++;
		}
		else
		{
			push(o, 0);
			cnt[1]++;
			if (o->stack[1]->head->next->data >= p1)
			{
				rotate(o, 1);
				cnt[2]++;
			}
		}
	}

	i = 0;
	while (i < cnt[0] || i < cnt[2])
	{
		if (i < cnt[0] && i < cnt[2])
			reverse_rotate(o, 2);
		else if (i < cnt[0])
			reverse_rotate(o, 0);
		else
			reverse_rotate(o, 1);
		i++;
	}
	a_to_b(o, p1, r, sorted);
	b_to_a(o, p2, p1, sorted);
	b_to_a(o, l, p2, sorted);
}