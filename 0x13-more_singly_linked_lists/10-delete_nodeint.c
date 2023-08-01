#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index in the list.
 * @head: Pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current_node, *temp;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    current_node = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(current_node);
        return (1);
    }

    while (current_node != NULL && count < index - 1)
    {
        current_node = current_node->next;
        count++;
    }

    if (current_node == NULL || current_node->next == NULL)
        return (-1);

    temp = current_node->next;
    current_node->next = temp->next;
    free(temp);

    return (1);
}

