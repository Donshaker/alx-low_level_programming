#ifndef DOG_H
#define DOG_H

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

/**
 * init_dog - Initializes a dog structure
 * @d: Pointer to the dog structure
 * @name: Pointer to the name of the dog
 * @age: Age of the dog
 * @owner: Pointer to the owner's name of the dog
 *
 * Description: This function initializes a dog structure with the given values.
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - Prints information about a dog
 * @d: Pointer to the dog structure
 *
 * Description: This function prints the name, age, and owner of a dog.
 */
void print_dog(struct dog *d);

/**
 * new_dog - Creates a new dog structure
 * @name: Pointer to the name of the dog
 * @age: Age of the dog
 * @owner: Pointer to the owner's name of the dog
 *
 * Return: Pointer to the newly created dog structure
 *
 * Description: This function creates a new dog structure and initializes it with
 * the given values for name, age, and owner.
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - Frees a dog structure
 * @d: Pointer to the dog structure to be freed
 *
 * Description: This function frees the memory allocated for a dog structure.
 */
void free_dog(dog_t *d);

#endif /* DOG_H */

