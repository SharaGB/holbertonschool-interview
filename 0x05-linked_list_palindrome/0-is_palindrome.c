#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow_ptr = *head, *fast_ptr = *head;
	int i = 0;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	if (*head != NULL && (*head)->next != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			if (slow_ptr->n != fast_ptr->next->n)
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}
