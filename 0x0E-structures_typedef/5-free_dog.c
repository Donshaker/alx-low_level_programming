#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees the memory allocated for a dog_t object
 * @d: Pointer to the dog_t object to free
 *
 * Description:
 *   This function frees the memory allocated for a dog_t object,
 *   including the memory for the name and owner strings. If the
 *   pointer `d` is NULL, the function does nothing.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

