#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		already(int *arr, int n, int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == n)
			return 1;
	return 0;
}

int    main()
{
	int arr[100];
	int size = 0, num;

	srand(time(NULL));
    while (size < 100)
	{
		num = rand() % 100 + 1;
		if (!already(arr, num, size))
			arr[size++] = num;
	}
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

