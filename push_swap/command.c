/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:43:32 by gkim              #+#    #+#             */
/*   Updated: 2021/11/18 13:02:10 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    swap(t_obj *o, int key)
{
	if (key == 2)
	{
		swap(o, 0);
		swap(o, 1);
		return ;
	}
	if (o->stack[key]->size < 2)
		return ;
	add_front(pop(o->stack[key]->head->next->next, o->stack[key]), o->stack[key]);
	add_back(init_node(1 + key), o->cmd);
	// printf("s%c\n", 'a' + key);
}

void	push(t_obj *o, int key)
{
	if (o->stack[!key]->size == 0)
		return ;
	add_front(pop(o->stack[!key]->head->next, o->stack[!key]), o->stack[key]);
	add_back(init_node(3 + key), o->cmd);
	// printf("p%c\n", 'a' + key);
}

int		rotate(t_obj *o, int key)
{	
	if (key == 2)
	{
		rotate(o, 0);
		rotate(o, 1);
		return (0);
	}
	if (o->stack[key]->size == 0)
		return (0);
	add_back(pop(o->stack[key]->head->next, o->stack[key]), o->stack[key]);
	add_back(init_node(5 + key), o->cmd);
	// printf("r%c\n", 'a' + key);
	return (1);
}

void	reverse_rotate(t_obj *o, int key)
{
	if (key == 2)
	{
		reverse_rotate(o, 0);
		reverse_rotate(o, 1);
		return ;
	}
	if (o->stack[key]->size == 0)
		return ;
	add_front(pop(o->stack[key]->last->prev, o->stack[key]), o->stack[key]);
	add_back(init_node(7 + key), o->cmd);
	// printf("rr%c\n", 'a' + key);
}
