#include "main.h"

/**
 * _strstr - Locates a substring in a string
 * @haystack: The string to be searched
 * @needle: The substring to be found
 *
 * Return: A pointer to the beginning of the located substring in haystack,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
		return haystack;

	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j]; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}

		if (needle[j] == '\0')
			return (haystack + i);
	}

	return NULL;
}

