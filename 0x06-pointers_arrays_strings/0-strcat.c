#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: Pointer to the resulting string 'dest'
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest;

    /* Find the end of the destination string */
    while (*ptr)
        ptr++;

    /* Append characters from the source string to the destination string */
    while (*src)
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    /* Add a terminating null byte */
    *ptr = '\0';

    return (dest);
}

