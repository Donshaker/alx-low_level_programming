#include "main.h"

/**
 * compare_chars - Compares characters recursively from both ends of the string
 * @s: The string to check
 * @start: The starting index of the substring to compare
 * @end: The ending index of the substring to compare
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise
 */
int compare_chars(char *s, int start, int end)
{
if (start >= end)
return (1); /* Substring is a palindrome */

if (s[start] != s[end])
return (0); /* Substring is not a palindrome */

return (compare_chars(s, start + 1, end - 1)); /* Recursive call */
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
int len = 0;

/* Find the length of the string */
while (s[len] != '\0')
len++;

/* Check if the string is empty */
if (len == 0)
return (1);

return (compare_chars(s, 0, len - 1));
}


