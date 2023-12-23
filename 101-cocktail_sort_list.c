#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *		in ascending order using the Cocktail shaker sort algorithm
 * @list: list to be sorted
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *h, *t;

	node = *list;
	if (!node || (!(node->prev) && !(node->next)))
		return;
	while (node->prev)
		node = node->prev;
	h = node;
	t = NULL;
	while (h != t && h->next != t)
	{
		while (node->next != t)
		{
			if (node->n > node->next->n)
			{
				node = node->next;
				swap(node);
				if (!(node->prev))
					*list = node;
				print_list(*list);
			}
			node = node->next;
		}
		t = node;
		while (node != h)
		{
			if (node->n < node->prev->n)
			{
				if (node->prev == h)
					h = node;
				swap(node);
				if (!(node->prev))
					*list = node;
				print_list(*list);
			}
			else
				node = node->prev;
		}
		node = node->next;
	}
}

/**
 * swap - changes node order with its previous node
 * @node: node to swap
 * Return: Nothing
 */
void swap(listint_t *node)
{
	if (node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else
		node->prev->next = NULL;

	node->next = node->prev;
	if (node->prev->prev)
		node->prev = node->prev->prev;
	else
		node->prev = NULL;

	node->next->prev = node;
	if (node->prev)
		node->prev->next = node;
}
