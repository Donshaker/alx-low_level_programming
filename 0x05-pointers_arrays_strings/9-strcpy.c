#include "main.h"

/**
 * my_strcpy - Copies a string from src to dest.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: The pointer to dest.
 */
char *my_strcpy(char *dest, const char *src)
{
    char *dest_ptr = dest;

    while ((*dest++ = *src++))
        ;

    return dest_ptr;
}

