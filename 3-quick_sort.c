#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using:
 *				"Lomuto partition scheme" Quick sort algorithm
 *				(pivot: last element of the partition being sorted)
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	lomuto_sort(array, size, array, size);
}

/**
 * lomuto_sort - quick_sort function (lomuto partition scheme)
 * @array: array in wich last element is placed at right index
 * @size: array size
 * @parray: parent array (to print)
 * @psize: parray size
 * Return: Nothing
 */
void lomuto_sort(int *array, size_t size, int *parray, size_t psize)
{
	size_t i, j, pivot;
	int tmp;

	if (size < 2)
		return;
	pivot = size - 1;
	i = 0;
	while (1)
	{
		for (; i < pivot && array[i] <= array[pivot]; i++)
			continue;
		if (i == pivot)
			break;
		for (j = i + 1; j < pivot && array[j] > array[pivot]; j++)
			continue;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(parray, psize);
		if (pivot == j)
		{
			pivot = i;
			break;
		}
	}
	lomuto_sort(array, pivot, parray, psize);
	lomuto_sort(&array[pivot], size - pivot, parray, psize);
}
