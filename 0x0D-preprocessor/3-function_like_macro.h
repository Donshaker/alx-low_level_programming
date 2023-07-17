#include <stdio.h>
#include "mymacros.h"

int main(void)
{
    int num = -5;
    int absNum = ABS(num);

    printf("The absolute value of %d is %d\n", num, absNum);
    return 0;
}


