#include "main.h"

/**
 * string_length - Returns the length of a string
 * @str: The input string
 *
 * Return: The length of the string
 */
int string_length(const char *str)
{
int length = 0;

while (str[length] != '\0')
length++;

return (length);
}
