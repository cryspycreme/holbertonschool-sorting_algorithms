#include <stdbool.h>
#include <stdio.h>
#include "sort.h"

/**
* insertion_sort - sorts an array of integers in ascending order using insertion sort
*
* @list: pointer to a pointer named list which contains a node
* @size: size of the array
* Return: nothing.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;

	if (*list == NULL)
                return;

	/*Traverse the list to sort each element*/
	while (current != NULL)
	{
		(*list)->next = current->next;

		if (sorted == NULL || sorted->n == current->n)
		{
			current->next = sorted;
		}

		if (sorted != NULL)
			sorted->prev = current;

		sorted = current;
		sorted->prev = NULL;

		 else {

            /*Pointer to traverse the sorted part*/
             listint_t *current_sorted = sorted;

            /*Find the correct position to insert*/
            while (current_sorted->next != NULL &&
                   current_sorted->next->n < current->n) {
                current_sorted = current_sorted->next;
            }

            /*Insert `curr` after `current_sorted`*/
            current->next = current_sorted->next;

            if (current_sorted->next != NULL)
                current_sorted->next->prev = current;

            current_sorted->next = current;
            current->prev = current_sorted;
        }

        current = next;
    }

    return sorted;
}
