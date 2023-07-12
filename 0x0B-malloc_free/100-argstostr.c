#include "main.h"
#include <stdlib.h>

char **argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int total_length = 0;
    int i, j, k;

    /* Calculate the total length of the arguments */
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            total_length++;
            j++;
        }
        total_length++; /* Account for the newline character */
    }

    /* Allocate memory for the concatenated string */
    char **result = malloc((ac + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;

    for (i = 0; i < ac; i++)
    {
        result[i] = malloc((total_length + 1) * sizeof(char));
        if (result[i] == NULL)
        {
            /* Free previously allocated memory */
            for (k = 0; k < i; k++)
                free(result[k]);
            free(result);
            return NULL;
        }

        /* Copy the arguments to the concatenated string */
        k = 0;
        for (j = 0; av[i][j] != '\0'; j++)
        {
            result[i][k] = av[i][j];
            k++;
        }
        result[i][k] = '\n'; /* Append newline character */
        result[i][k + 1] = '\0'; /* Null-terminate the string */
    }

    result[ac] = NULL; /* Null-terminate the array of strings */

    return result;
}

