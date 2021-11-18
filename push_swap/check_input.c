/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:37:04 by gkim              #+#    #+#             */
/*   Updated: 2021/11/09 19:24:41 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int			isSorted(t_stack *s)
{
	t_node	*next, *curr;

	curr = s->head->next;

	while (curr->next->next)
	{
		next = curr->next;
		if (curr->data > next->data)
			return (0);
		curr = next;
	}
	return (1);
}

static int	print_error()
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

static int	already(int *arr, int n, int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == n)
			return 1;
	return 0;
}

// 중복값이 있을 경우 return 1, 없을 경우 return 0;
int			insert_array(char *argv, int *arr, int size)
{
	char	err_flag;
	int		num;

	err_flag = 0;
	num = ps_atoi(argv, &err_flag);
	if (err_flag)
		return (print_error());
	if (already(arr, num, size))
		return (print_error());
	arr[size] = num;
	return (0);
}