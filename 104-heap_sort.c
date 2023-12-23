#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 *				using the 'shift-down' Heap sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (size < 2)
		return;
	for (i = size - 1; i > 0; i--)
	{
		heapify(array, i + 1, size);
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		print_array(array, size);
	}
}

/**
 * heapify - rearranges the array heap to be a max heap
 * @array: array to be rearranged
 * @hsize: rearrangement zone
 * @size: array size
 * Return: Nothing
 */
void heapify(int *array, size_t hsize, size_t size)
{
	size_t i, k;
	int tmp;

	for (i = hsize - 1; i > 0; i--)
	{
		k = (i - 1) / 2;
		while (1)
		{
			tmp = array[k];
			if ((k + 1) * 2 < hsize)
			{
				if (array[(k + 1) * 2] > array[k * 2 + 1] && array[(k + 1) * 2] > array[k])
				{
					array[k] = array[(k + 1) * 2];
					array[(k + 1) * 2] = tmp;
					k = (k + 1) * 2;
					print_array(array, size);
				} else if (array[k * 2 + 1] > array[k])
				{
					array[k] = array[k * 2 + 1];
					array[k * 2 + 1] = tmp;
					k = k * 2 + 1;
					print_array(array, size);
				} else
					break;
			} else if (k * 2 + 1 == hsize - 1)
			{
				if (array[k * 2 + 1] > array[k])
				{
					array[k] = array[k * 2 + 1];
					array[k * 2 + 1] = tmp;
					k = k * 2 + 1;
					print_array(array, size);
				} else
					break;
			} else
				break;
		}
	}
}
