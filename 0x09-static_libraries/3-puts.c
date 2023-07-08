#include "main.h"

/**
 * _puts - Prints a string to stdout
 * @s: The string to be printed
 */
void _puts(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}

