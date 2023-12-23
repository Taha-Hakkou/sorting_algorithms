#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 *					"Hoare partition scheme" Quick sort algorithm
 *					Pivot should always be the last element of the partition being sorted
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	hoare_sort(array, size, array, size);
}

/**
 * hoare_sort - implements quick_sort with hoare partition scheme
 * @array: array to be sorted
 * @size: array size
 * @parray: parent array (to be printed)
 * @psize: parent size (to be printed)
 * Return: Nothing
 */
void hoare_sort(int *array, size_t size, int *parray, size_t psize)
{
	size_t i, j, pivot;
	int tmp;

	if (size < 2)
		return;
	pivot = size - 1;
	i = 0;
	j = size - 1;
	while (1)
	{
		for (; i < pivot && array[i] <= array[pivot]; i++)
			continue;
		for (; j > pivot && array[j] >= array[pivot]; j--)
			continue;
		if (j > i)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (pivot == i)
				pivot = j;
			else if (pivot == j)
				pivot = i;
			print_array(parray, psize);
		}
		else
			break;
	}
	hoare_sort(array, pivot, parray, psize);
	hoare_sort(&array[pivot], size - pivot, parray, psize);
}
