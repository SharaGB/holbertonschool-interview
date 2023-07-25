#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to first node.
 * Return: the node address where the loop starts or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ptr1 = NULL;
	listint_t *ptr2 = NULL;

	if (head == NULL)
		return (NULL);
	ptr1 = head;
	ptr2 = head;

	while (ptr1 && ptr2 && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;

		if (ptr1 == ptr2)
		{
			while (1)
			{
				ptr2 = ptr1;
				while (ptr2->next != ptr1 && ptr2->next != head)
					ptr2 = ptr2->next;
				if (ptr2->next == head)
					break;
				head = head->next;
			}
			return (head);
		}
	}
	return (NULL);
}
