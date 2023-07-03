#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: Pointer to the string
 * @accept: Pointer to the string containing acceptable bytes
 *
 * Return: Number of bytes in the initial segment of s which consist only of
 *         bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int match;

	while (*s != '\0')
	{
		match = 0;

		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				match = 1;
				break;
			}

			accept++;
		}

		if (match == 0)
			return count;

		count++;
		s++;
		accept = accept - count;
	}

	return (count);
}

