#include "main.h"
#include <stdlib.h>

char *str_concat(char *s1, char *s2)
{
    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    unsigned int len1 = 0, len2 = 0;

    // Calculate the lengths of the strings
    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    char *result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
        return NULL;

    // Copy the contents of s1
    for (unsigned int i = 0; i < len1; i++)
        result[i] = s1[i];

    // Copy the contents of s2
    for (unsigned int i = 0; i < len2; i++)
        result[len1 + i] = s2[i];

    result[len1 + len2] = '\0'; // Null terminate the concatenated string

    return result;
}

