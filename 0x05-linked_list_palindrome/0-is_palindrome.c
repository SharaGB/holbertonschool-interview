#include "lists.h"
/**
 * recursive_palindrome - function to check if a linked list is a palindrome
 * @head: head of the linked list
 * @current: current node
 *
 * Return: pointer to something if palindrome, else NULL
 */
listint_t *recursive_palindrome(listint_t *current, listint_t *head)
{
	listint_t *next = NULL;

	if (current == NULL)
		return (head);
	next = recursive_palindrome(current->next, head);
	if (next == NULL)
		return (NULL);
	if (next->n == current->n)
	{
		if (current == head)
			return (current);
		return (next->next);
	}
	return (NULL);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);

	if (recursive_palindrome(*head, *head) == NULL)
		return (0);
	return (1);
}
