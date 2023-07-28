#include <stdio.h>

void print_before_main(void) __attribute__((constructor));

/**
 * print_before_main - Prints the specified lines before the main function.
 */
void print_before_main(void)
{
    printf("You're beat! and yet, you must allow,\n"
           "I bore my house upon my back!\n");
}

int main(void)
{
    /* Your main function code goes here */

    return (0);
}



