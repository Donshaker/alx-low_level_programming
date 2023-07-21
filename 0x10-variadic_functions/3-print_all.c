#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format.
 * @format: The list of types of arguments passed to the function.
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char current_char;
    char *separator = "";
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        current_char = format[i];

        if (current_char == 'c')
        {
            printf("%s%c", separator, va_arg(args, int));
        }
        else if (current_char == 'i')
        {
            printf("%s%d", separator, va_arg(args, int));
        }
        else if (current_char == 'f')
        {
            printf("%s%f", separator, va_arg(args, double));
        }
        else if (current_char == 's')
        {
            str = va_arg(args, char *);
            if (str == NULL)
                str = "(nil)";
            printf("%s%s", separator, str);
        }

        separator = ", ";
        i++;
    }

    va_end(args);
    printf("\n");
}

