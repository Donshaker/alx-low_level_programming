#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the details of a struct dog
 * @d: Pointer to the struct dog to print
 *
 * Description:
 *   This function prints the details of a struct dog, including its name, age,
 *   and owner. If any element of the struct is NULL, it prints (nil) instead.
 *   If the pointer `d` is NULL, nothing is printed.
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		char *name = d->name != NULL ? d->name : "(nil)";
		char *owner = d->owner != NULL ? d->owner : "(nil)";

		printf("Name: %s\n", name);
		printf("Age: %.6f\n", d->age);
		printf("Owner: %s\n", owner);
	}
}

