#include "main.h"

/**
 * puts - Prints a string followed by a new line, to stdout
 * @str: The string to be printed
 */
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str++);
}
_putchar('\n');
}


