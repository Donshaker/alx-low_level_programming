#include <stdio.h>

void __attribute__((constructor)) before_main(void);

/**
 * before_main - Function to be executed before the main function.
 *
 * Description: This function prints the specified message before
 * the main function is executed.
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n"
	       "(A tortoise, having pretty good sense of a hare's nature, challenges one to a race.)\n");
}


