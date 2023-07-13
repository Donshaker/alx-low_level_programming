#include "main.h"
#include <stdlib.h>

char *create_array(unsigned int size, char c)
{
    if (size == 0)
        return (NULL);

    char *str;
    unsigned int i;

    str = malloc(sizeof(char) * size);
    if (str == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        str[i] = c;

    return (str);
}



