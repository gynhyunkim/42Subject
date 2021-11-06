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

#include "include/push_swap.h"

void	three_sort(t_obj *o, int key)
{
	int	n1, n2, n3;

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
	{
		reverse_rotate(o, key);
		reverse_rotate(o, key);
	}
}

void	five_param(t_obj *o, int *sorted)
{
	int		i;
	t_stack	*s;

	push(o, 1);
	push(o, 1);

	three_sort(o, 0);
	i = 2;
	s = o->stack[0];
	while (i--)
	{
		push(o, 0);
		if (s->head->next->data > s->last->prev->data)
			rotate(o, 0);
		else if (s->head->next->data > s->head->next->next->data)
			three_sort(o, 0);
	}
}

void	sort(t_obj *o, int key)
{
	int	n1, n2, n3;

	n1 = o->stack[key]->head->next->data;
	n2 = o->stack[key]->head->next->next->data;
	if (o->stack[key]->size < 3)
	{
		if (n1 > n2)
			swap(o, key);
		return ;
	}
	n3 = o->stack[key]->head->next->next->next->data;
	
	if (n1 > n2 && n1 < n3)
		swap(o, key);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
	else if (n1 < n2 && n3 < n2)
	{
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
		swap(o, key);
	}
	else if (n1 > n2 && n2 > n3)
	{
		swap(o, key);
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
		swap(o, key);
	}
	else if (n1 > n2 && n1 > n3)
	{
		swap(o, key);
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
}

void	sort_r(t_obj *o, int key)
{
	int	n1, n2, n3;

	n1 = o->stack[key]->head->next->data;
	n2 = o->stack[key]->head->next->next->data;
	if (o->stack[key]->size < 3)
	{
		if (n1 < n2)
			swap(o, key);
		return ;
	}
	n3 = o->stack[key]->head->next->next->next->data;
	
	if (n2 > n1 && n2 > n3) // 231
		swap(o, key);
	else if (n1 > n2 && n1 > n3 && n2 < n3) // 312
	{
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
	else if (n1 > n2 && n3 > n2) // 213
	{
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
		swap(o, key);
	}
	else if (n1 < n2 && n2 < n3) // 123 
	{
		swap(o, key);
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
		swap(o, key);
	}
	else if (n1 < n2 && n2 > n3) // 132
	{
		swap(o, key);
		rotate(o, key);
		swap(o, key);
		reverse_rotate(o, key);
	}
}

void	a_to_b(t_obj *o, int *sorted, int l, int r)
{
	int	p1, p2, i, ra, rb;

	if (r - l < 4)
	{
		sort(o, 0);
		return ;
	}
	p1 = sorted[l + (r - l) / 3];
	p2 = sorted[l + (r - l) / 3 * 2];
	i = l;
	ra = 0;
	rb = 0;
	/*
	1/3 지점의 값을 p1, 2/3 지점의 값을 p2로 설정하고
	p2보다 큰 값들은 a의 뒤로 보내고
	p2보다 작지만 p1보다 큰 값들은 b의 뒤로 보낸다
	p1보다 작은 값들은 p1의 앞에 그대로 둔다
	*/
	while (i < r)
	{
		if (o->stack[0]->head->next->data >= p2)
		{
			rotate(o, 0);
			ra++;
		}
		else
		{
			push(o, 1);
			if (o->stack[1]->head->next->data >= p1)
			{
				rotate(o, 1);
				rb++;
			}
		}
		i++;
	}
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
	a_to_b(o, sorted, l + (r - l) / 3 * 2, r);
	b_to_a(o, sorted, l + (r - l) / 3, l + (r - l) / 3 * 2);
	b_to_a(o, sorted, l, l + (r - l) / 3);
}

void	b_to_a(t_obj *o, int *sorted, int l, int r)
{
	int p1, p2, i, ra, rb;

	if (r - l < 4)
	{
		sort_r(o, 1);
		while (l++ < r)
			push(o, 0);
		return ;
	}
	p1 = sorted[l + (r - l) / 3];
	p2 = sorted[l + (r - l) / 3 * 2];
	i = l;
	ra = 0;
	rb = 0;
	while (i++ < r)
	{
		if (o->stack[1]->head->next->data < p1)
		{
			rotate(o, 1);
			rb++;
		}
		else
		{
			push(o, 0);
			if (o->stack[0]->head->next->data < p2)
			{
				rotate(o, 0);
				ra++;
			}
		}
	}
	a_to_b(o, sorted, l + (r - l) / 3 * 2, r);
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
	a_to_b(o, sorted, l + (r - l) / 3, l + (r - l) / 3 * 2);
	b_to_a(o, sorted, l, l + (r - l) / 3); 
}

