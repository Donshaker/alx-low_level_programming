#include "main.h"
#include <stdio.h>

int main(void)
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    print_diagsums((int *)matrix, 3);

    return (0);
}

