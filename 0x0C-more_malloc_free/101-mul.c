#include <stdio.h>
#include <stdlib.h>

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The result of the multiplication
 */
unsigned int multiply(unsigned int num1, unsigned int num2)
{
	unsigned int result = 0;

	while (num2 > 0)
	{
		if (num2 & 1)
			result += num1;

		num1 <<= 1;
		num2 >>= 1;
	}

	return result;
}

/**
 * is_valid_number - Checks if a string represents a valid positive number
 * @str: The string to check
 *
 * Return: 1 if the string is a valid positive number, 0 otherwise
 */
int is_valid_number(char *str)
{
	if (str == NULL || *str == '\0')
		return 0;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return 0;
		str++;
	}

	return 1;
}

int main(int argc, char *argv[])
{
	unsigned int num1, num2;

	if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%u\n", multiply(num1, num2));

	return 0;
}

