#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *				using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, tmp;

	if (size < 2)
		return;
	for (i = size - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
}
