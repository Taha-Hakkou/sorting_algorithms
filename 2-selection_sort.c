#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *					using the Selection sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, low;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		low = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[low])
				low = j;
		if (low != i)
		{
			tmp = array[i];
			array[i] = array[low];
			array[low] = tmp;
			print_array(array, size);
		}
	}
}
