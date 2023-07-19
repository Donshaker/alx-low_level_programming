#include "function_pointers.h"

/**
 * print_name - Prints a name.
 * @name: The name to be printed.
 * @f: A function pointer to be applied on each character of the name.
 *
 * Description: This function takes a name and applies a function
 *              pointed to by `f` on each character of the name.
 *              The function `f` should take a character pointer as
 *              an argument and return void.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		while (*name)
		{
			f(name);
			name++;
		}
	}
}

