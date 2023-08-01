#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t node_count = 0;
    const listint_t *current_node = head;
    const listint_t *slow = head;
    const listint_t *fast = head;

    while (current_node != NULL)
    {
        printf("[%p] %d\n", (void *)current_node, current_node->n);
        node_count++;

        slow = slow->next;
        if (fast != NULL && fast->next != NULL)
            fast = fast->next->next;
        else
            fast = NULL;

        if (slow == fast)
        {
            printf("-> [%p] %d\n", (void *)current_node->next, current_node->next->n);
            exit(98);
        }

        current_node = current_node->next;
    }

    return (node_count);
}

