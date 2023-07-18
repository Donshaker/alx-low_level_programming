#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Pointer to a character string representing the dog's name
 * @age: Age of the dog
 * @owner: Pointer to a character string representing the owner's name
 *
 * Return: Pointer to the newly created dog_t object, or NULL if the
 *         function fails.
 *
 * Description:
 *   This function creates a new dog object by allocating memory for a
 *   dog_t structure and copying the provided name and owner strings.
 *   If the memory allocation fails, NULL is returned.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_name, *new_owner;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_name = strdup(name);
	if (new_name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_owner = strdup(owner);
	if (new_owner == NULL)
	{
		free(new_name);
		free(new_dog);
		return (NULL);
	}

	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;

	return (new_dog);
}

