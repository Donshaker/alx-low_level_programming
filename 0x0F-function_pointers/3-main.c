#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error\n");
        return 98;
    }

    int num1 = atoi(argv[1]);
    char operator = argv[2][0];
    int num2 = atoi(argv[3]);

    int result;
    if (!validate_operator(operator))
    {
        printf("Error\n");
        return 99;
    }

    if ((operator == '/' || operator == '%') && num2 == 0)
    {
        printf("Error\n");
        return (100);
    }

    result = perform_operation(num1, operator, num2);
    printf("%d\n", result);

    return (0);
}

