#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Initialize va_list */
	va_start(args, n);

	/* Print numbers */
	for (i = 0; i < n; i++)
	{
		/* Check if separator is NULL to avoid printing it */
		if (separator != NULL)
		{
			printf("%d", va_arg(args, int));

			/* Print separator if not the last number */
			if (i < n - 1)
				printf("%s", separator);
		}
		else
		{
			printf("%d", va_arg(args, int));
		}
	}

	/* Clean up the va_list */
	va_end(args);

	printf("\n");
}

