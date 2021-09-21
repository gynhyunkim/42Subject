/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:04 by gkim              #+#    #+#             */
/*   Updated: 2021/07/09 16:45:47 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	array_swap(int *arr, int a, int b)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int	partition(int *arr[], int p, int r)
{
	int	idx, i, pivot;

	pivot = arr[0][r];
	i = p;
	idx = p;
	while (idx <= r)
	{
		if (arr[0][idx] <= pivot)
		{
			array_swap(arr[0], idx, i);
			array_swap(arr[1], idx, i++);
		}
		idx++;
	}
	return (i - 1);
}

void	quick_sort(int *a[], int p, int r)
{
	int	q;

	if (p < r)
	{
		q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

int main(int argc, char **argv)
{
	int i;
	t_node	*node;
	t_obj	*o;
	int	*array[2];

	if (argc > 1)
	{
		array[0] = malloc(sizeof(int) * (argc - 1));
		array[1] = malloc(sizeof(int) * (argc - 1));
		o = init_stack();
		i = 1;
		while (i < argc)
		{
			add_front(init_node(ft_atoi(argv[i])), o->stack[0]);
			array[0][i - 1] = ft_atoi(argv[i]);
			array[1][i - 1] = i - 1;
			i++;
		}
		if (argc == 4)
			sort(o, 0);
		else if (argc == 6)
			five_param(o);
		else
		{
			quick_sort(array, 0, argc - 2);
			quick_sort_stack(o, 0, argc - 1, array);
		}
		//i = 0;
		// while (i < argc - 1)
		// 	printf("%d ", array[1][i++]);
		// printf("\n");
	}
	// printf("%d\n", o->stack[0]->size);
	
	print(o, 0);
	print(o, 1);
}