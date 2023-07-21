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
	unsigned int i = 0, count = 0;
	char *str_arg;
	char current_char;

	va_start(args, format);

	while (format && format[i])
	{
		current_char = format[i];

		if ((current_char == 'c' || current_char == 'i' || current_char == 'f' || current_char == 's') && count > 0)
			printf(", ");

		switch (current_char)
		{
		case 'c':
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			str_arg = va_arg(args, char *);
			if (str_arg == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", str_arg);
			break;
		default:
			count--;
			break;
		}
		i++;
		count++;
	}

	va_end(args);
	printf("\n");
}

