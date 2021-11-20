/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:01:40 by gkim              #+#    #+#             */
/*   Updated: 2021/11/20 22:16:08 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_obj	*init_stack(void)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	obj->stack[0] = malloc(sizeof(t_stack));
	obj->stack[0]->size = 0;
	obj->stack[0]->head = init_node(0);
	obj->stack[0]->last = init_node(0);
	obj->stack[0]->head->next = obj->stack[0]->last;
	obj->stack[0]->last->prev = obj->stack[0]->head;
	obj->stack[1] = malloc(sizeof(t_stack));
	obj->stack[1]->size = 0;
	obj->stack[1]->head = init_node(0);
	obj->stack[1]->last = init_node(0);
	obj->stack[1]->head->next = obj->stack[1]->last;
	obj->stack[1]->last->prev = obj->stack[1]->head;
	obj->cmd = malloc(sizeof(t_stack));
	obj->cmd->size = 0;
	obj->cmd->head = init_node(0);
	obj->cmd->last = init_node(0);
	obj->cmd->head->next = obj->cmd->last;
	obj->cmd->last->prev = obj->cmd->head;
	return (obj);
}

void	stack_clear(t_stack *s)
{
	t_node	*node;
	t_node	*next;

	node = s->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

void	free_stack(t_obj *o)
{
	stack_clear(o->stack[0]);
	stack_clear(o->stack[1]);
	stack_clear(o->cmd);
	free(o->stack[0]);
	free(o->stack[1]);
	free(o->cmd);
	free(o);
}
