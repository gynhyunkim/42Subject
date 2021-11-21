/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:04 by gkim              #+#    #+#             */
/*   Updated: 2021/11/21 13:54:41 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	check_input(t_obj *o, int *array, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (insert_array(argv[i], array, i - 1))
			return (1);
		add_back(init_node(ft_atoi(argv[i])), o->stack[0]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_obj	*o;
	int		*array;

	if (argc > 1)
	{
		array = malloc(sizeof(int) * (argc - 1));
		o = init_stack();
		if (!check_input(o, array, argc, argv) && !is_sorted(o->stack[0]))
		{
			if (argc == 4)
				three_sort(o, 0);
			else if (argc <= 6)
				five_param(o);
			else
			{
				arr_quick_sort(array, 0, argc - 2);
				a_to_b(o, array, 0, argc - 1);
			}
		}
		cmd_parsing(o->cmd);
		free_stack(o);
		free(array);
	}
}
