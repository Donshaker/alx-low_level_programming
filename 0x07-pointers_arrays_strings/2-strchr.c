#include "main.h"
#include <stdio.h>

int main(void)
{
    char str[] = "Hello, World!";
    char c = 'o';
    char *result = _strchr(str, c);

    if (result)
        printf("Character '%c' found at position %ld\n", c, result - str);
    else
        printf("Character '%c' not found in the string.\n", c);

    return (0);
}


