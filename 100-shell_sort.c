#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *				using the 'Knuth sequence' Shell sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (size < 2)
		return;
	for (gap = 1; gap <= size / 3; )
		gap = gap * 3 + 1;
	for (; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && tmp < array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
