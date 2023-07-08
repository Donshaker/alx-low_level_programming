#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment of a string
 *           which consists only of characters from another string
 * @s: The string to be searched
 * @accept: The string containing the characters to be matched
 *
 * Return: The number of characters in s that consist only of characters from
 *         accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s && _strchr(accept, *s))
	{
		count++;
		s++;
	}

	return count;
}

