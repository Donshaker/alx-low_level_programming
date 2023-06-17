#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int i, j, k;

    for (i = 0; i < 8; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            for (k = j + 1; k < 10; k++)
            {
                putchar(i + '0'); /* Print the first digit */
		putchar(j + '0'); /* Print the second digit */
                putchar(k + '0'); /* Print the third digit */

                if (i != 7 || j != 8 || k != 9) /* Check if it's not the last combination */
                {
                    putchar(','); /* Print the comma */
                    putchar(' '); /* Print the space */
                }
            }
        }
    }

    putchar('\n'); /* Print a newline character */

    return 0;
}
