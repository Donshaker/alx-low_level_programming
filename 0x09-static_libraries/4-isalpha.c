#include "main.h"

/**
 * _isalpha - Checks if a character is an alphabetic letter
 * @c: The character to be checked
 *
 * Return: 1 if the character is an alphabetic letter, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


