#include "main.h"
#include <stdlib.h>

char *_strdup(char *str)
{
    if (str == NULL)
        return NULL;

    unsigned int length = 0;

    // Calculate the length of the string
    while (str[length] != '\0')
        length++;

    char *duplicate = malloc((length + 1) * sizeof(char));
    if (duplicate == NULL)
        return NULL;

    // Copy the string to the duplicate
    for (unsigned int i = 0; i <= length; i++)
        duplicate[i] = str[i];

    return duplicate;
}
}

