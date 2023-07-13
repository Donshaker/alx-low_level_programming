#include <stdlib.h>
#include "main.h"

/**
 * free_words - Frees the memory allocated for an array of strings.
 * @words: The array of strings to be freed.
 * @len: The length of the array.
 */
void free_words(char **words, int len)
{
	int i;

	for (i = 0; i < len; i++)
		free(words[i]);

	free(words);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words) or NULL if it fails.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, count = 0, word_len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = strlen(str);

	/* Count the number of words in the string */
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			word_len++;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				count++;
		}
	}

	if (count == 0)
		return (NULL);

	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	/* Allocate memory for each word and copy the characters */
	j = 0;
	for (i = 0; i < len && j < count; i++)
	{
		if (str[i] != ' ')
		{
			word_len++;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				words[j] = malloc((word_len + 1) * sizeof(char));
				if (words[j] == NULL)
				{
					free_words(words, j);
					return (NULL);
				}
				strncpy(words[j], str + i - word_len + 1, word_len);
				words[j][word_len] = '\0';
				j++;
				word_len = 0;
			}
		}
	}

	words[count] = NULL;
	return (words);
}


