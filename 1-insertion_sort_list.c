#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *			in ascending order using the Insertion sort algorithm
 * @list: doubly linked list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp;

	node = *list;
	if (!node || (!(node->next) && !(node->prev))) /* size < 2 */
		return;
	while (node->prev)
		node = node->prev;
	for (; node; node = node->next)
		for (tmp = node; tmp->prev && tmp->prev->n > node->n;)
		{
			if (tmp->next)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			else
				tmp->prev->next = NULL;

			tmp->next = tmp->prev;
			if (tmp->prev->prev)
				tmp->prev = tmp->prev->prev;
			else
			{
				tmp->prev = NULL;
				*list = tmp;
			}

			tmp->next->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;

			print_list(*list);
		}
}
