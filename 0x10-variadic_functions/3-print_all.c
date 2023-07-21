#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function.
 *          c: char
 *          i: integer
 *          f: float
 *          s: char* (if the string is NULL, print (nil) instead)
 *          Any other char should be ignored.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char *separator = "";

    va_start(args, format);

    while (format && format[i])
    {
        if (i > 0)
            separator = ", ";

        switch (format[i])
        {
            case 'c':
                printf("%s%c", separator, va_arg(args, int));
                break;
            case 'i':
                printf("%s%d", separator, va_arg(args, int));
                break;
            case 'f':
                printf("%s%f", separator, va_arg(args, double));
                break;
            case 's':
                {
                    char *str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(nil)";
                    printf("%s%s", separator, str);
                }
                break;
        }
        i++;
    }

    va_end(args);
    printf("\n");
}

