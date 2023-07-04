#include "main.h"
#include <stdio.h>

int main(void)
{
    char haystack[] = "Hello, World!";
    char needle[] = "World";
    char *result = _strstr(haystack, needle);

    if (result)
        printf("Substring found at position: %ld\n", result - haystack);
    else
        printf("Substring not found in the string.\n");

    return (0);
}



