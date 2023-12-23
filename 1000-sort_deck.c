#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck of cards to be sorted
 * Return: Nothing
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *n, *tmp;

	if (!deck || (!((*deck)->prev) && !((*deck)->next)))
		return;
	while ((*deck)->prev)
		*deck = (*deck)->prev;
	n = (*deck)->next;
	while (n)
	{
		tmp = n->prev;
		while (tmp)
		{
			if (tmp->card->kind > n->card->kind || (tmp->card->kind == n->card->kind
						&& indexOf(tmp->card->value) > indexOf(n->card->value)))
				tmp = tmp->prev;
			else
				break;
		}
		if (n->prev != tmp)
		{
			n->prev->next = n->next;
			if (n->next)
				n->next->prev = n->prev;
			n->prev = tmp;
			if (tmp)
			{
				tmp->next->prev = n;
				n = n->next;
				tmp->next->prev->next = tmp->next;
				tmp->next = tmp->next->prev;
			} else
			{
				(*deck)->prev = n;
				n = n->next;
				(*deck)->prev->next = *deck;
				*deck = (*deck)->prev;
			}
		} else
			n = n->next;
	}
}

/**
 * indexOf - maps a card value to an ordering index
 * @value: card's value
 * Return: ordering index
 */
int indexOf(const char *value)
{
	int i;
	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
		if (!strcmp(value, values[i]))
			break;
	return (i);
}
