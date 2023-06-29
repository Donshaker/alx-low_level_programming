#include <stdio.h>

int main(void)
{
int a[5] = {0, 1, 2, 3, 4};
int *p = &a[2];
printf("a[2] = %d\n", *(p + 0));

p[0] = 98;

printf("a[2] = %d\n", *(p + 0));

return (0);
}

