#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 *				using the 'LSD' Radix sort algorithm
 * @array: array to be sorted (only >= 0 numbers)
 * @size: array size
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t i, j;
	int high, mod, lsd, d;
	int *carray;

	if (size < 2)
		return;
	high = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > high)
			high = array[i];

	for (mod = 1; high % mod < high; mod *= 10)
	{
		carray = malloc(size * sizeof(int));
		i = 0;
		for (d = 0; d <= 9; d++)
		{
			for (j = 0; j < size; j++)
			{
				lsd = array[j] % (mod * 10) / mod;
				if (lsd == d)
					carray[i++] = array[j];
			}
			if (i == size)
				break;
		}
		for (i = 0; i < size; i++)
			array[i] = carray[i];
		print_array(array, size);
		free(carray);
	}
}
