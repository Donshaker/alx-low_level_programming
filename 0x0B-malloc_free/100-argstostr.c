#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * argstostr - Concatenates all the arguments of a program.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: A pointer to the new string, or NULL if it fails.
 *         Each argument is followed by a newline character '\n'.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k = 0, length = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the length of the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			length++;
		length++; /* Account for the newline character */
	}

	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Copy the arguments into the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n'; /* Append the newline character */
		k++;
	}

	str[k] = '\0'; /* Add the null terminator at the end */
	return (str);
}

