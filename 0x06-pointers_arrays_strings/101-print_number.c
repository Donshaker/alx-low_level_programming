#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to print
 */
void print_number(int n)
{
    if (n < 0)
    {
        _putchar('-');  /* Print minus sign for negative numbers */
        n = -n;  /* Convert the number to positive */
    }

    if (n / 10 != 0)
    {
        print_number(n / 10);  /* Recursively print the digits except the last one */
    }

    _putchar('0' + (n % 10));  /* Print the last digit as a character */
}

