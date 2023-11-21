#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: the doubly linked list to be sorted
 *
 * Return: no return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *sorted = NULL, *tmp = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;

	sorted = (*list)->next;
	while (sorted != NULL)
	{
		current = sorted;
		sorted = sorted->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			tmp = current->prev;
			current->prev = tmp->prev;
			tmp->next = current->next;
			current->next = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = current;
			else
				*list = current;

			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			tmp->prev = current;
			print_list(*list);
		}
	}
}
