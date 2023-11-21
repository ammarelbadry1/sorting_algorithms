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
 * partition - put the pivot in its right place
 *
 * @array: the array contains the pivot
 * @low: The low bound of the array
 * @high: The high bound of the array
 *
 * Return: the index of the pivot
*/
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	return (i + 1);
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
		pivot = partition(array, low, high);
		print_array(array, size);
		sort(array, low, pivot - 1, size);
		sort(array, pivot + 1, high, size);
	}
}
