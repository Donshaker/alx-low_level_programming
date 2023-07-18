#include "dog.h"

/**
 * init_dog - Initializes a struct dog
 * @d: Pointer to the struct dog to initialize
 * @name: Pointer to a character string representing the dog's name
 * @age: Age of the dog
 * @owner: Pointer to a character string representing the owner's name
 *
 * Description: This function initializes the members of a struct dog with the
 *              provided values for name, age, and owner.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

