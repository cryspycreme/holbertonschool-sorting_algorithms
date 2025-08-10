#include <stdbool.h>
#include <stdio.h>
#include "sort.h"
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
        listint_t *back = node->prev, *current = node;
        /*NULL, 19, 48, 9, 71, 13, NULL*/

        back->next = current->next;
        if (current->next)
                current->next->prev = back;
        current->next = back;
        current->prev = back->prev;
        back->prev = current;
        if (current->prev)
                current->prev->next = current;
        else
                *list = current;
        return (current);
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	/* If the list itself is NULL or has only one element, no sorting is needed, so it returns immediately.*/
	if (list == NULL || (*list)->next == NULL)
		return;
	
	/*Start with the second node in the list because in insertion sort, we treat the first node as already "sorted."*/
	node = (*list)->next;
	while (node) /*loop until end of list*/
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
