#include "main.h"

/**
 * print_string - Prints a string followed by a new line
 * @str: The string to be printed
 */
void print_string(const char *str)
{
int i = 0;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
_putchar('\n');
}


