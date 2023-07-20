#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int num;

	/* Initialize va_list */
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		/* Get the next argument */
		num = va_arg(args, int);

		/* Print the number */
		printf("%d", num);

		/* Print the separator if it's not NULL and not the last number */
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	/* Clean up the va_list */
	va_end(args);

	/* Print a new line at the end */
	printf("\n");
}

