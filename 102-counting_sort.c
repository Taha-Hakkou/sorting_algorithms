#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 *					using the Counting sort algorithm
 * @array: array to be sorted (only >= 0 numbers)
 * @size: array size
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *carray, tmp;
	size_t max, i, j;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > (int)max)
			max = array[i];
	carray = malloc((max + 1) * sizeof(int));
	memset(carray, 0, max + 1);
	for (i = 0; i < size; i++)
		for (j = array[i]; j < max + 1; j++)
			carray[j]++;
	print_array(carray, max + 1);
	tmp = 0;
	for (i = 0; i < size; i++)
	{
		for (j = tmp; carray[j] == (int)i; j++)
			tmp++;
		array[i] = tmp;
	}
	free(carray);
}
