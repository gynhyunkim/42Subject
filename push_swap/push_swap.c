/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:04 by gkim              #+#    #+#             */
/*   Updated: 2021/05/24 17:09:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	t_list *node;
	t_obj *o;

	if (argc > 1)
	{
		o = init_stack();
		i = 1;
		while (i < argc)
			add_back(*argv[i] - '0', o->stack[0]);
	}
	node = o->stack[0]->head;
	while (node->next)
	{
		node = node->next;
		printf("%d\n", node->data);
	}	
}