/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:47:14 by gkim              #+#    #+#             */
/*   Updated: 2021/05/24 15:39:18 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *init_node(int data)
{
	t_list  *node;
	
	node = malloc(sizeof(t_list));
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	add_back(t_list *node, t_stack *stack)
{
	node->last = stack->last;
	node->prev = stack->last->prev;
	stack->last->prev->next = node;
	stack->last->prev = node;
	stack->size++;
}

void	add_front(t_list *node, t_stack *stack)
{
	node->prev = stack->head;
	node->next = stack->head->next;
	stack->head->next->prev = node;
	stack->head->next = node;
	stack->size++;
}

t_list	*pop(t_list *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	stack->size--;
	return (node);
}
