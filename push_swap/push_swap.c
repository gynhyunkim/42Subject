/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:04 by gkim              #+#    #+#             */
/*   Updated: 2021/11/21 01:02:00 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	check_input(t_obj *o, int *array, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (insert_array(argv[i], array, i))
			return (1);
		add_back(init_node(ft_atoi(argv[i])), o->stack[0]);
		i++;
	}
	return (0);
}

static void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i++] = NULL;
	}
	free(argv);
}

static int	length_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_obj	*o;
	int		*array;

	if (argc > 1)
	{
		argv = ft_split(argv[1], ' ');
		argc = length_argv(argv);
		array = malloc(sizeof(int) * (argc));
		o = init_stack();
		if (argv && !check_input(o, array, argc, argv)
			&& !is_sorted(o->stack[0]))
		{
			arr_quick_sort(array, 0, argc - 1);
			if (argc == 3)
				three_sort(o, 0);
			else if (argc == 5)
				five_param(o);
			else
				a_to_b(o, array, 0, argc);
		}
		cmd_parsing(o->cmd);
		free_stack(o);
		free(array);
		free_argv(argv);
	}
}
