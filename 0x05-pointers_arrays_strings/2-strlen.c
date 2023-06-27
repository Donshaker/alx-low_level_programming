#include "main.h"
#include "string.h"

/**
 * string_length - Returns the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int string_length(char *str)
{
int length = 0;

while (str[length] != '\0')
length++;

return length;
}
