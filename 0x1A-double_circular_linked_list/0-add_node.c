#include "list.h"
#include "stdlib.h"
#include <string.h>
/**
 * add_node_end - Add a new node to the end of a double circular linked list.
 * @list: pointer to first node.
 * @str: given string to be added.
 * Return: the address of the new element, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	List *temp;
	List *start;
	char *strNode;

	if (!str || !list)
		return (NULL);
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	strNode = strdup(str);
	if (!strNode)
	{
		free(new);
		return (NULL);
	}
	new->str = strNode;

	if (*list == NULL)
	{
		*list = new;
		new->next = new->prev = new;
	}
	else
	{
		start = temp = *list;
		while (temp->next != start)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		new->next = start;
		start->prev = new;
	}
	return (new);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular
 * linked list.
 * @list: pointer to first node.
 * @str: given string to be added.
 * Return: the address of the new element, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	List *temp;
	List *start;
	char *strNode;

	if (!str || !list)
		return (NULL);
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	strNode = strdup(str);
	if (!strNode)
	{
		free(new);
		return (NULL);
	}
	new->str = strNode;

	if (*list == NULL)
	{
		*list = new;
		new->next = new->prev = new;
	}
	else
	{
		new->next = start = temp = *list;
		*list = new;
		new->next->prev = new;
		while (temp->next != start)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}

	return (new);
}
