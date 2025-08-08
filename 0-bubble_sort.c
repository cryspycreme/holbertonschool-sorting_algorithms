#include <stdbool.h>
#include <stdio.h>
#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order using bubble sort
*
* @array: the array to be sorted
* @size: size of the array
* Return: nothing.
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - 1)) /*size - 1 because it wont be compared to anything*/
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
