/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:47:14 by gkim              #+#    #+#             */
/*   Updated: 2021/06/17 20:39:15 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist  *init_node(int data)
{
	t_dlist  *node;
	
	node = malloc(sizeof(t_dlist));
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	add_back(t_dlist *node, t_stack *stack)
{
	node->next = stack->last;
	node->prev = stack->last->prev;
	stack->last->prev->next = node;
	stack->last->prev = node;
	stack->size++;
}

void	add_front(t_dlist *node, t_stack *stack)
{
	node->prev = stack->head;
	node->next = stack->head->next;
	stack->head->next->prev = node;
	stack->head->next = node;
	stack->size++;
}

t_dlist	*pop(t_dlist *node, t_stack *stack)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	stack->size--;
	return (node);
}
