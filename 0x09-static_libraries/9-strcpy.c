#include "main.h"

/**
 * _strcpy - Copies a string, including the null terminator, from src to dest
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the resulting string (dest)
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return dest_start;
}

