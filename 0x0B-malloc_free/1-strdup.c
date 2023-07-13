#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: The string to be duplicated.
 *
 * Return: On success, returns a pointer to the duplicated string.
 *         It returns NULL if insufficient memory was available or if str is NULL.
 */
char *_strdup(char *str)
{
	unsigned int length = 0;
	char *duplicate, *ptr;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;

	duplicate = malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	ptr = duplicate;

	/* Copy the string to the newly allocated memory */
	while (*str)
		*ptr++ = *str++;

	*ptr = '\0';

	return (duplicate);
}
}

