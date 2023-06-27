#include "main.h"

/**
 * print_reverse - Prints a string in reverse, followed by a new line.
 * @str: The string to be printed.
 */
void print_reverse(char *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;

    for (length -= 1; length >= 0; length--)
        _putchar(str[length]);

    _putchar('\n');
}

