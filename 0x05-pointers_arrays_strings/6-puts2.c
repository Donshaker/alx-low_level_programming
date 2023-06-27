#include "main.h"

/**
 * print_every_other - Prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str: The string to be printed.
 */
void print_every_other(char *str)
{
    int index = 0;

    while (str[index] != '\0')
    {
        _putchar(str[index]);
        index += 2;
    }

    _putchar('\n');
}

