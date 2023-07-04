#include "main.h"
#include <stdio.h>

int main(void)
{
    char *s = "Hello";
    char to[] = "World";

    printf("Before: s = %s\n", s);
    set_string(&s, to);
    printf("After: s = %s\n", s);

    return (0);
}

