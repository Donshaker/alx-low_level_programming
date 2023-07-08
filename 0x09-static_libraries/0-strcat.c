#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string to append to
 * @src: The source string to append from
 *
 * Return: A pointer to the resulting string (dest)
 */
char *_strcat(char *dest, char *src)
{
	char *dest_start = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return dest_start;
}


