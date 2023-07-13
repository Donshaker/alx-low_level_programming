#include <stdlib.h>
#include "main.h"

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */
static int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return count;
}

/**
 * extract_word - Extracts a word from a string
 * @str: The input string
 * @start: The starting index of the word
 * @end: The ending index of the word
 *
 * Return: The extracted word
 */
static char *extract_word(char *str, int start, int end)
{
	int i, j;
	char *word;

	word = malloc((end - start + 2) * sizeof(char));
	if (word == NULL)
		return NULL;

	for (i = start, j = 0; i <= end; i++, j++)
		word[j] = str[i];
	word[j] = '\0';

	return word;
}

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: Pointer to an array of strings (words)
 *         The last element of the array is NULL
 *         NULL if str is NULL or str is ""
 */
char **strtow(char *str)
{
	int i, j, num_words, word_index;
	char **words;

	if (str == NULL || *str == '\0')
		return NULL;

	num_words = count_words(str);
	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return NULL;

	word_index = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			int start = i;

			while (str[i] != ' ' && str[i] != '\0')
				i++;

			words[word_index] = extract_word(str, start, i - 1);
			if (words[word_index] == NULL)
			{
				free_words(words);
				return NULL;
			}

			word_index++;
		}
	}

	words[word_index] = NULL;
	return words;
}

/**
 * free_words - Frees the memory allocated for an array of words
 * @words: The array of words
 */
void free_words(char **words)
{
	int i;

	if (words == NULL)
		return;

	for (i = 0; words[i] != NULL; i++)
		free(words[i]);

	free(words);
}

