#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *low = *head;
	listint_t *fast = *head;
	int i = 0;

	if (!*head || !(*head))
	{
		return (1);
	}
	if (*head != NULL && (*head)->next != NULL)
	{
		while (fast != NULL && fast->next != NULL)
		{
			if (low->n != fast->next->n)
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}
