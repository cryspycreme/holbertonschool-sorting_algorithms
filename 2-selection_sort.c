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

void selection_sort(int *array, size_t size)
{
	size_t i, j; /*marker to loop through array*/
	size_t min_idx; /*assume current position stores min element*/
	int temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		min_idx = i;
		
		/*this loops through the array to find the index of smallest no.*/
		while (j < size)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
			j++;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
    			array[min_idx] = temp;
			print_array(array, size);
		}
		i++;
	}
}
