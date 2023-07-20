#include "variadic_functions.h"

/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of arguments to sum.
 * @...: The variable number of arguments.
 *
 * Return: The sum of all the arguments.
 */
int sum_them_all(const unsigned int n, ...)
{
    if (n == 0)
        return 0;

    int sum = 0;
    va_list args;
    unsigned int i;

    va_start(args, n);

    for (i = 0; i < n; i++)
        sum += va_arg(args, int);

    va_end(args);

    return sum;
}

