#include "main.h"

/**
 * _strpbrk - Locates the first occurrence of any byte from accept in s
 * @s: The string to be searched
 * @accept: The string containing bytes to be matched
 *
 * Return: A pointer to the matching byte in s, or NULL if no match is found
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        char *current_accept = accept;
        while (*current_accept != '\0')
        {
            if (*s == *current_accept)
                return s;
            current_accept++;
        }
        s++;
    }
    return (NULL);
}

