#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: Variable number of integers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    int current_num;

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        current_num = va_arg(args, int);

        printf("%d", current_num);

        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }

    va_end(args);
    printf("\n");
}
