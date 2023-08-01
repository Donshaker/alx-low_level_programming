#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in the list.
 * @head: Pointer to a pointer to the head of the list.
 * @idx: The index where the new node should be added. Index starts at 0.
 * @n: The integer value to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *current_node = *head;
    unsigned int count = 0;

    if (head == NULL)
        return (NULL);

    if (idx == 0)
    {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
            return (NULL);

        new_node->n = n;
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    while (current_node != NULL)
    {
        if (count == idx - 1)
        {
            new_node = malloc(sizeof(listint_t));
            if (new_node == NULL)
                return (NULL);

            new_node->n = n;
            new_node->next = current_node->next;
            current_node->next = new_node;
            return (new_node);
        }

        count++;
        current_node = current_node->next;
    }

    return (NULL);
}

