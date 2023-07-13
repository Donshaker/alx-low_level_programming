#include <stdlib.h>
#include "main.h"

int count_words(char *str);
char *extract_word(char *str, int *index);
void free_words(char **words);

char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int num_words = count_words(str);
    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    int word_index = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            int start = i;
            char *word = extract_word(str, &i);
            if (word != NULL)
            {
                words[word_index] = word;
                word_index++;
            }
            else
            {
                free_words(words);
                return NULL;
            }
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
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count++;
        i++;
    }
    return count;
}

char *extract_word(char *str, int *index)
{
    int start = *index;
    int word_length = 0;
    while (str[*index] != ' ' && str[*index] != '\0')
    {
        word_length++;
        (*index)++;
    }

    char *word = malloc((word_length + 1) * sizeof(char));
    if (word == NULL)
        return NULL;

    int i, j;
    for (i = start, j = 0; i < *index; i++, j++)
        word[j] = str[i];

    word[word_length] = '\0';
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

