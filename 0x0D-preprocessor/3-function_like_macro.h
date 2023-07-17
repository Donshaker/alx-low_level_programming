#include <stdio.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int main(void)
{
    int num = -5;
    int absNum = ABS(num);

    printf("The absolute value of %d is %d\n", num, absNum);

    return (0);
}

