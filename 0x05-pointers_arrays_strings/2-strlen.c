#include "main.h"

/**
 * strlen - returns the length of a string
 * @s: The string
 * Return: length 
 */
int strlen(char *s)
{
int longi = 0;

while (*s != '\0')
{
longi++;
s++;
}

return (longi);
}
