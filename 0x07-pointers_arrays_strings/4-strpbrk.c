#include "main.h"
#include <stdio.h>

int main(void)
{
    char str[] = "Hello, World!";
    char accept[] = "aeiou";
    char *result = _strpbrk(str, accept);

    if (result)
        printf("First vowel found in the string: %c\n", *result);
    else
        printf("No vowel found in the string.\n");

    return (0);
}


