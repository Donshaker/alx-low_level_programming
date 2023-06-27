#include "main.h"
#include "string.h"

/**
 * strlen - Returns the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int strlen(char *str)
{
int length = 0;

while (str[length] != '\0')
length++;

return length;
}
