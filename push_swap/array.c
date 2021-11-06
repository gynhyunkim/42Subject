
#include "include/push_swap.h"

static int	partition(int *arr, int p, int r)
{
	int	idx, i, pivot, tmp;

	pivot = arr[r];
	i = p;
	idx = p;
	while (idx <= r)
	{
		if (arr[idx] <= pivot)
		{
			tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
			i++;
		}
		idx++;
	}
	return (i - 1);
}

void	arr_quick_sort(int *a, int p, int r)
{
	int	q;

	if (p < r)
	{
		q = partition(a, p, r);
		arr_quick_sort(a, p, q - 1);
		arr_quick_sort(a, q + 1, r);
	}
}
