#include "lists.h"

/**
* insert_node - inserts a node in a sorted singly linked list.
* @head: pointer to the head of the list.
* @number: the number that will be inserted into the list.
* Return: a pointer to the inserted node or NULL if failed.
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *before_insert, *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = number;

	if (!(*head))
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}

	before_insert = *head;

	if (before_insert->n > number)
	{
		new_node->next = before_insert;
		*head = new_node;
		return (new_node);
	}

	while (before_insert->next && before_insert->next->n < number)
		before_insert = before_insert->next;

	new_node->next = before_insert->next;
	before_insert->next = new_node;

	return (new_node);
}
