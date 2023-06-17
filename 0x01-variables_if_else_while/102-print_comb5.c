#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int i, j;

    for (i = 0; i < 100; i++)
    {
        for (j = i; j < 100; j++)
        {
            if (i != j)
		     {
                putchar(i / 10 + '0'); /* Print the tens digit of the first number */
                putchar(i % 10 + '0'); /* Print the ones digit of the first number */

                putchar(' '); /* Print the space */

                putchar(j / 10 + '0'); /* Print the tens digit of the second number */
                putchar(j % 10 + '0'); /* Print the ones digit of the second number */

                if (i != 99 || j != 99) /* Check if it's not the last combination */
                {
                    putchar(','); /* Print the comma */
                    putchar(' '); /* Print the space */
                }
		    }
        }
    }

    putchar('\n'); /* Print a newline character */

    return (0);
}
