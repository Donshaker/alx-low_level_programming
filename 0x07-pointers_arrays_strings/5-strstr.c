#include "main.h"
#include <stdio.h>

int main(void)
{
    char haystack[] = "Hello, world!";
    char needle[] = "world";

    char *result = _strstr(haystack, needle);

    if (result != NULL)
        printf("Substring found: %s\n", result);
    else
        printf("Substring not found\n");

    return (0);
}


