#include "variadic_functions.h"

/**
 * sum_them_all - Sums all its parameters.
 * @n: The number of parameters to sum.
 *
 * Return: The sum of all the parameters.
 *         If n is 0, return 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	/* Check if n is 0 */
	if (n == 0)
		return (0);

	/* Initialize va_list and get the first argument */
	va_start(args, n);

	/* Sum all the parameters */
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	/* Clean up the va_list */
	va_end(args);

	return (sum);
}

