#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t node_count = 0;
    listint_t *current_node, *next_node;

    if (h == NULL)
        return (0);

    current_node = *h;

    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
        node_count++;
    }

    *h = NULL;
    return (node_count);
}

