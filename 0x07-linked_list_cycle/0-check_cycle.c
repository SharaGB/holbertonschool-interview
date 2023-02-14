#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: linked list
 * Return: 1 or 0
 */
int check_cycle(listint_t *list)
{
    listint_t *s, *f;

    s = f = list;
    while (s && f && f->next)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
            return (1);
    }
    return (0);
}