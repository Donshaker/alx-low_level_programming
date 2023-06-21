#include "main.h"

/**
 * print_alphabet - Make the alphabet
 *
 * Reyurn:void
 */

void print_alphabet(void)
{
    char letter = 'a';

    while (letter <= 'z')
    {
        _putchar(letter);
        letter++;
    }
