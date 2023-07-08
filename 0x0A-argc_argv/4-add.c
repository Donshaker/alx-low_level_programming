#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int i, num, sum;

if (argc == 1)
{
printf("0\n");
return 0;
}

sum = 0;

for (i = 1; i < argc; i++)
{
for (num = 0; argv[i][num]; num++)
{
if (!isdigit(argv[i][num]))
{
printf("Error\n");
return (1);
}
}

sum += atoi(argv[i]);
}

printf("%d\n", sum);

return (0);
}

