#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *				using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: array size (equal to 2^k, where k >= 0 {when array is not NULL …})
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	b_sort(array, size, size, 1);
}

/**
 * b_sort - bitonic_sort with more args for printability
 * @array: array to be sorted
 * @size: sorting partition size
 * @psize: parent array size (to be printed)
 * @up: sorting direction
 * Return: Nothing
 */
void b_sort(int *array, size_t size, size_t psize, int up)
{
	size_t gap, i;
	int tmp/*, *carray*/;

	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, psize, up ? "UP" : "DOWN");
	print_array(array, size);
	b_sort(array, size / 2, psize, 1);
	b_sort(&array[size / 2], size / 2, psize, 0); /* carray = &array[size / 2]; */
	for (gap = size / 2; gap; gap /= 2)
	{
		if (up)
		{
			for (i = 0; i <= size - gap - 1; i++)
			{
				if (array[i] > array[i + gap])
				{
					tmp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = tmp;
				}
				if ((i - gap - 1) % (gap * 2) == 0)
					i += gap;
			}
		} else
			for (i = size - 1; i >= size - gap; i--)
			{
				if (array[i] > array[i - gap])
				{
					tmp = array[i];
					array[i] = array[i - gap];
					array[i - gap] = tmp;
				}
				if ((size - i - gap - 1) % (gap * 2) == 0)
					i -= gap;
				print_array(array, size);
			}
		printf("%lu\n", gap);
	}
	printf("Result [%lu/%lu] (%s):\n", size, psize, up ? "UP" : "DOWN");
	print_array(array, size);
}
