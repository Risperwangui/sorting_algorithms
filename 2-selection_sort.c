#include "sort.h"
/**
 * swap_ints - swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array
 * @array: this is the array
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i;
		for (j = i + 1; j < size; j++)
			minimum = (array[j] < *minimum) ? (array + j) : minimum;
		if ((array + i) != minimum)
		{
			swap_ints(array + i, minimum);
			print_array(array, size);
		}
	}
}
