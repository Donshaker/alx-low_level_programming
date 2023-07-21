#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: Operator passed as argument to the program
 *
 * Return: Pointer to the corresponding function; NULL if operator not found
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", add},
        {"-", sub},
        {"*", mul},
        {"/", div_op},
        {"%", mod},
        {NULL, NULL}
    };

    int i = 0;

    while (ops[i].op != NULL)
    {
        if (*(ops[i].op) == *s && s[1] == '\0')
            return (ops[i].f);
        i++;
    }

    return (NULL);
}

