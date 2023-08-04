#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to convert and print in binary.
 */
void print_binary(unsigned long int n)
{
	int shift;
	int leading_zeroes = 1;

	for (shift = sizeof(unsigned long int) * 8 - 1; shift >= 0; shift--)
	{
		unsigned long int bit = (n >> shift) & 1;

		if (bit == 1)
			leading_zeroes = 0;

		if (!leading_zeroes)
			_putchar(bit + '0');
	}

	if (leading_zeroes)
		_putchar('0');
}

