#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = _strlen_recursion(s);

    if (len <= 1)  /* Base case: empty string or single character is a palindrome */
        return 1;

    return is_palindrome_helper(s, s + len - 1);
}

/**
 * is_palindrome_helper - Recursive helper function to check if a string is a palindrome
 * @start: The starting character of the substring to check
 * @end: The ending character of the substring to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome_helper(char *start, char *end)
{
    if (start >= end)  /* Base case: substring is a palindrome */
        return 1;

    if (*start != *end)  /* Base case: substring is not a palindrome */
        return 0;

    return is_palindrome_helper(start + 1, end - 1);
}

