#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            putchar(i + '0'); /* Print the first digit */
            putchar(j + '0'); /* Print the second digit */
 if (i != 8 || j != 9) /* Check if it's not the last combination */
            {
                putchar(','); /* Print the comma */
                putchar(' '); /* Print the space */
            }
        }
    }

    putchar('\n'); /* Print a newline character */

    return (0);
}
