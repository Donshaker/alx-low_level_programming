#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to convert and print in binary.
 */
void print_binary(unsigned long int n)
{
	int shift, leading_zeroes;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	shift = sizeof(unsigned long int) * 8 - 1;
	leading_zeroes = 1;

	while (shift >= 0)
	{
		unsigned long int bit = (n >> shift) & 1;

		if (bit == 1)
			leading_zeroes = 0;

		if (!leading_zeroes)
			_putchar(bit + '0');

		shift--;
	}
}

