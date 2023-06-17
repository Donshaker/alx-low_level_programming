#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	int i;

    for (i = 0; i < 9; i++)
    {
        putchar(i + '0'); /* Print the current number */

        if (i != 8) /* Check if it's not the last number */
        {
		putchar(','); /* Print the comma */
            putchar(' '); /* Print the space */
        }
    }
 putchar('\n'); /* Print a newline character */

    return 0;
}
