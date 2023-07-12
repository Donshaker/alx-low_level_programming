#include "main.h"
#include <stdlib.h>

char *argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int total_length = 0;
    int i, j, k;

    // Calculate the total length of the arguments
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            total_length++;
            j++;
        }
        total_length++; // Account for the newline character
    }

    // Allocate memory for the concatenated string
    char *result = malloc((total_length + 1) * sizeof(char));
    if (result == NULL)
        return NULL;

    // Copy the arguments to the concatenated string
    k = 0;
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            result[k] = av[i][j];
            j++;
            k++;
        }
        result[k] = '\n'; // Append newline character
        k++;
    }

    result[k] = '\0'; // Null-terminate the concatenated string

    return result;
}

