#include "main.h"

/**
 * string_toupper - Changes all lowercase letters of a string to uppercase
 * @str: The string to modify
 *
 * Return: Pointer to the modified string 'str'
 */
char *string_toupper(char *str)
{
char *ptr = str;

while (*ptr)
{
if (*ptr >= 'a' && *ptr <= 'z')
{
/* Convert lowercase letter to uppercase */
*ptr = *ptr - 'a' + 'A';
}
ptr++;
}

return (str);
}

