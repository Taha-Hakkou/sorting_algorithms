#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 *				using the Merge sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *carray, *array2;
	size_t m = 0, n = 0, i;

	if (size < 2)
		return;
	array2 = &array[size / 2];
	merge_sort(array, size / 2);
	merge_sort(array2, (size + 1) / 2);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, size / 2);
	printf("[right]: ");
	print_array(array2, (size + 1) / 2);

	carray = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		if (m < size / 2 && n < (size + 1) / 2)
		{
			if (array[m] < array2[n])
				carray[i] = array[m++];
			else
				carray[i] = array2[n++];
		}
		else if (m < size / 2)
			carray[i] = array[m++];
		else
			carray[i] = array2[n++];
	}
	memcpy(array, carray, size * sizeof(int));
	printf("[Done]: ");
	print_array(array, size);
	free(carray);
}
