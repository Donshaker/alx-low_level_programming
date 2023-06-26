#include "main.h"

/**
 * strlen - Returns the length of a string
 * @s: The input string
 * Return: The length of the string
 */
int strlen(char *s)
{
int longi = 0;

while (*s != '\0')
longi++;
s++;

return (longi);
}
