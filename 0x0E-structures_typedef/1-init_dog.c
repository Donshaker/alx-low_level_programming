#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * init_dog - Initializes a dog structure
 * @d: Pointer to the dog structure
 * @name: Pointer to the name of the dog
 * @age: Age of the dog
 * @owner: Pointer to the owner's name of the dog
 *
 * Description: This function initializes a dog structure with the given values.
 * It stores a copy of name and owner in the new structure.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name ? strdup(name) : NULL;
	d->age = age;
	d->owner = owner ? strdup(owner) : NULL;
}

