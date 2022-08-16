#include "lists.h"
/**
 * insert_node - Inserts a new node at the sorted position
 * @head: Head of the list
 * @number: Number to insert
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *tmp = *head;
    listint_t *new_node = malloc(sizeof(listint_t));

    if (new_node == NULL)
        return (NULL);
    new_node->n = number;

    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = NULL;
        return (new_node);
    }
    if (tmp->n >= number)
    {
        new_node->next = tmp;
        *head = new_node;
        return (new_node);
    }

    while (tmp->next != NULL)
    {
        if (tmp->next->n > number)
        {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return (new_node);
        }
        tmp = tmp->next;
    }
    tmp->next = new_node;
    new_node->next = NULL;
    return (new_node);
}
