#include "sort.h"

/**
 * A function that sorts an array of integers in ascending order 
 * using the Selection sort algorithm
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int aux = 0;
	size_t i = 0, j = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != i)
		{
			aux = array[i];
			array[i] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}
