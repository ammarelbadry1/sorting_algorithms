#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {3, 2, 1};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	check_array(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

/**
 * check_array - check if an array is sorted ascending
 *
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: no return
*/
void check_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] <= array[i + 1])
			continue;
		printf("not sorted!\n");
		return;
	}
	printf("sorted!\n");
}

/**
 * check_list - check if a linked list is sorted ascending
 *
 * @list: the list to be checked
 *
 * Return: no return
*/
void check_list(listint_t *list)
{
	listint_t *current = list;

	while (current->next != NULL)
	{
		if (current->n <= current->next->n)
		{
			current = current->next;
			continue;
		}
		printf("not sorted!\n");
		return;
	}
	printf("sorted!\n");
}
