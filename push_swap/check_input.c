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
int			insert_array(int num, int *arr, int size)
{
	if (already(arr, num, size))
		return (print_error());
	arr[size] = num;
	return (0);
}