#include "sort.h"
/**
 * insertion_sort_list - it sorts a doubly linked list
 * in ascending order that uses insertion sorting
 * @list: this pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *one, *two, *tmp;

	if (!list || !*list)
		return;

	two = (*list);
	one = (*list)->next;

	while (one)
	{
		while (two && one->n < two->n)
		{
			if (two->prev)
				two->prev->next = one;
			else
				*list = one;

			if (one->next)
				one->next->prev = two;

			tmp = one->next;
			one->next = two;
			one->prev = two->prev;
			two->next = tmp;
			two->prev = one;

			ptint_list(*list);
			two = one->prev;
		}
		one = one->next;

		if (one)
			two = one->prev;
	}
}

