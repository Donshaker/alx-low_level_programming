#include "main.h"

/**
 * _strncat - Concatenates two strings, up to n bytes from src
 * @dest: The destination string to append to
 * @src: The source string to append from
 * @n: The maximum number of bytes to be appended
 *
 * Return: A pointer to the resulting string (dest)
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return dest;
}

