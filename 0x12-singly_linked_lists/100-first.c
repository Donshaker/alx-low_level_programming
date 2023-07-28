#include <stdio.h>
#include "lists.h"

/* Function prototype for the constructor */
void print_message(void) __attribute__((constructor));

/**
 * print_message - Function to be executed before main function.
 *
 * Description: This function prints the specified message before
 * the main function is executed.
 */
void print_message(void)
{
    printf("You're beat! and yet, you must allow,\n"
           "I bore my house upon my back!\n");
}

int main(void)
{
    /* Add test code or the rest of your program here */

    return 0;
}

