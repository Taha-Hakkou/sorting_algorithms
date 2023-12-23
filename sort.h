#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*----------------------- listint_t -----------------------*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*---------------------- Prototypes -----------------------*/

void print_array(const int *, size_t);
void print_list(const listint_t *);

void swap(listint_t *);
void lomuto_sort(int *, size_t, int *, size_t);
void hoare_sort(int *, size_t, int *, size_t);
void heapify(int *, size_t, size_t);
void b_sort(int *, size_t, size_t, int);

void bubble_sort(int *, size_t);
void insertion_sort_list(listint_t **);
void selection_sort(int *, size_t);
void quick_sort(int *, size_t);
void shell_sort(int *, size_t);
void cocktail_sort_list(listint_t **);
void counting_sort(int *, size_t);
void merge_sort(int *, size_t);
void heap_sort(int *, size_t);
void radix_sort(int *, size_t);
void bitonic_sort(int *, size_t);
void quick_sort_hoare(int *, size_t);

#endif /* SORT_H */
