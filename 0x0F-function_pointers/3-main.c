#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 if number of arguments is wrong,
 *         99 if the operator is invalid, 100 if division by 0 occurs.
 */
int main(int argc, char *argv[])
{
    int num1, num2;
    int result;
    int (*func_ptr)(int, int);

    if (argc != 4)
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        return 98;
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    if (argv[2][1] != '\0' || (argv[2][0] != '+' && argv[2][0] != '-' &&
                               argv[2][0] != '*' && argv[2][0] != '/' &&
                               argv[2][0] != '%'))
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        return 99;
    }

    func_ptr = get_op_func(argv[2]);

    if (func_ptr == NULL)
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        return 99;
    }

    if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        return 100;
    }

    result = func_ptr(num1, num2);
    _putchar(result + '0');
    _putchar('\n');

    return 0;
}

