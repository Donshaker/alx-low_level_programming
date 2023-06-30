#include <stdio.h>

/**
 * print_buffer - Prints the content of a buffer
 * @b: The buffer to print
 * @size: The size of the buffer
 */
void print_buffer(char *b, int size)
{
    int i, j;
    unsigned char byte;

    if (size <= 0)
    {
        printf("\n");
        return;
    }

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                byte = *(b + i + j);
                printf("%02x", byte);
            }
            else
            {
                printf("  ");
            }

            if (j % 2 != 0)
                printf(" ");
        }

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                byte = *(b + i + j);
                if (byte >= 32 && byte <= 126)
                    printf("%c", byte);
                else
                    printf(".");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

