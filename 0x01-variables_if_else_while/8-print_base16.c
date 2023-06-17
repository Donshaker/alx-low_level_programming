#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int i;

    for (i = 0; i < 10; i++)
        putchar(i + '0'); /* Print numbers 0-9 */

    for (i = 0; i < 6; i++)
        putchar(i + 'a'); /* Print letters a-f */
     putchar('\n'); /* Print a newline character */

    return (0);
}
