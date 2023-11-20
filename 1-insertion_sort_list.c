#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list - the doubly linked list to be sorted
 *
 * Return: no return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	current = *list;
	if (current == NULL)
		return;
	while (current->next != NULL)
	{
		current = current;
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			print_list(*list);
		}
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
			current = current->prev;
		}
		current = current->next;
	}
}

void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *tmp1, *tmp2;

	tmp1 = node1->prev;
	tmp2 = node2->next;

	if (tmp1 != NULL)
		tmp1->next = node2;
	else
		*head = node2;
	if (tmp2 != NULL)
		tmp2->prev = node1;
	
	node1->prev = node2;
	node1->next = tmp2;
	node2->prev = tmp1;
	node2->next = node1;
}

/* void insertion_sort_list(int *array, size_t size)
{
	unsigned long int current, current, tmp;

	for (current = 0; current < size - 1; current++)
	{
		if (array[current] > array[current + 1])
		{
			tmp = array[current];
			array[current] = array[current + 1];
			array[current + 1] = tmp;
		}
		for (current = current; current > 0; current--)
		{
			if (array[current] < array[current - 1])
			{
				tmp = array[current];
				array[current] = array[current - 1];
				array[current - 1] = tmp;
			}
		}
	}
} */
