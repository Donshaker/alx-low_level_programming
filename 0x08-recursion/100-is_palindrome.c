#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
int len = 0;
int i;

/* Find the length of the string */
while (s[len] != '\0')
len++;

/* Check if the string is empty */
if (len == 0)
return (1);

/* Compare characters from both ends */
for (i = 0; i < len / 2; i++)
{
if (s[i] != s[len - 1 - i])
return (0);
}

return (1);
}


