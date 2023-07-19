#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: The array to iterate over.
 * @size: The size of the array.
 * @action: A function pointer to be applied on each element of the array.
 *
 * Description: This function takes an integer array and its size, and
 *              applies a function pointed to by `action` on each element
 *              of the array.
 *              The function `action` should take an integer as an argument
 *              and return void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL && action != NULL)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}

