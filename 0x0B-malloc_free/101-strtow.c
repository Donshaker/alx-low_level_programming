#include "main.h"
#include <stdlib.h>

int count_words(char *str);
char *extract_word(char *str, int *index);
void free_words(char **words);

char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int num_words = count_words(str);
    if (num_words == 0)
        return NULL;

    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    int word_index = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            words[word_index] = extract_word(str, &i);
            if (words[word_index] == NULL)
            {
                free_words(words);
                return NULL;
            }

            word_index++;
        }
        else
        {
            i++;
        }
    }

    words[word_index] = NULL;

    return words;
}

int count_words(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            count++;
            while (str[i] != ' ' && str[i] != '\0')
                i++;
        }
        else
        {
            i++;
        }
    }

    return count;
}

char *extract_word(char *str, int *index)
{
    int start = *index;
    while (str[*index] != ' ' && str[*index] != '\0')
        (*index)++;

    int word_length = *index - start;
    char *word = malloc((word_length + 1) * sizeof(char));
    if (word == NULL)
        return NULL;

    int i, j;
    for (i = start, j = 0; i < *index; i++, j++)
        word[j] = str[i];

    word[j] = '\0';

    return word;
}

void free_words(char **words)
{
    if (words == NULL)
        return;

    int i = 0;
    while (words[i] != NULL)
    {
        free(words[i]);
        i++;
    }

    free(words);
}

