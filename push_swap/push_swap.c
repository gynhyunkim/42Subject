/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:04 by gkim              #+#    #+#             */
/*   Updated: 2021/11/18 13:29:15 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	print(t_obj *o, int key)
{
	t_node	*node;

	node = o->stack[key]->head;
	while (node->next->next)
	{
		node = node->next;
		printf("%d\n", node->data);
	}
	printf("-\n");
	if (key == 0)
		printf("a\n");
	else
		printf("b\n");
}

int main(int argc, char **argv)
{
	int		i;
	t_node	*node;
	t_obj	*o;
	int		*array;

	if (argc > 1)
	{
		array = malloc(sizeof(int) * (argc - 1));
		o = init_stack();
		i = 1;
		while (i < argc)
		{
			if (insert_array(argv[i], array, i - 1))
			{
				free_stack(o);
				free(array);
				exit(1);
			}
			add_back(init_node(ft_atoi(argv[i])), o->stack[0]);
			i++;
		}
		if (!isSorted(o->stack[0]))
		{
			if (argc == 4)
				three_sort(o, 0);
			else if (argc == 6)
				five_param(o, array);
			else
			{
				arr_quick_sort(array, 0, argc - 2);
				a_to_b(o, array, 0, argc - 1);
			}
		}
		
	}
	
	// print(o, 0);
	// print(o, 1);
	cmd_parsing(o->cmd);
	// printf("%d\n", cmd_parsing(o->cmd));
	// cnt_cmd(o->cmd);
	free_stack(o);
	free(array);
	// system("leaks push_swap");
}