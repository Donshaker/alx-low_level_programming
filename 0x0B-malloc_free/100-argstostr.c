#include "main.h"
#include <stdlib.h>

char *argstostr(int ac, char **av);

char *argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int total_length = 0;
    int i, j;
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

    char *result = malloc((total_length + 1) * sizeof(char));
    if (result == NULL)
        return NULL;

    int index = 0;
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            result[index] = av[i][j];
            index++;
            j++;
        }
        result[index] = '\n';
        index++;
    }
    result[index] = '\0';

    return result;
}

