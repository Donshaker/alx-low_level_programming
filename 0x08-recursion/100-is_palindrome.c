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

    return is_palindrome_helper(s, 0, len - 1);
}

/**
 * is_palindrome_helper - Recursive helper function to check if a string is a palindrome
 * @s: The string to check
 * @start: The starting index of the substring to check
 * @end: The ending index of the substring to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome_helper(char *s, int start, int end)
{
    if (start >= end)  /* Base case: substring is a palindrome */
        return 1;

    if (s[start] != s[end])  /* Base case: substring is not a palindrome */
        return 0;

    return is_palindrome_helper(s, start + 1, end - 1);
}

