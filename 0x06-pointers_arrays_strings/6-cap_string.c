#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to capitalize
 *
 * Return: Pointer to the capitalized string 'str'
 */
char *cap_string(char *str)
{
int i;
int capitalize_next = 1;

for (i = 0; str[i] != '\0'; i++)
{
if (capitalize_next && str[i] >= 'a' && str[i] <= 'z')
{
/* Convert lowercase letter to uppercase */
str[i] = str[i] - 'a' + 'A';
}

capitalize_next = 0;

/* Check if the current character is a separator */
if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
str[i] == ',' || str[i] == ';' || str[i] == '.' ||
str[i] == '!' || str[i] == '?' || str[i] == '"' ||
str[i] == '(' || str[i] == ')' || str[i] == '{' ||
str[i] == '}')
{
capitalize_next = 1;
}
}

return (str);
}

