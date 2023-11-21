#include "sort.h"

/**
 * quick_sort - the Entry point of the program
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: no return
*/
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

/**
 * swap_ints - Swap two integers in an array.
 *
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Return: no return
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - put the pivot in its right place
 *
 * @array: the array contains the pivot
 * @left: The low bound of the array
 * @right: The high bound of the array
 * @size: the size of the array
 *
 * Return: the index of the pivot
*/
int partition(int *array, int left, int right, size_t size)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @low: The low bound of the array
 * @high: The high bound of the array
 * @size: the array size
 *
 * Return: no return
*/
void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort(array, low, pivot - 1, size);
		sort(array, pivot + 1, high, size);
	}
}
