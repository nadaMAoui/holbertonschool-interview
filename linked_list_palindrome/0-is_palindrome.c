#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 0 if it is not a palindrome and 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *start = *head, *end = *head;

	if (!head || !*head)
		return (1);

	if (!palindrome_check(start, end))
		return (0);

	return (1);
}

/**
 * palindrome_check - checks if a linked list is a palindrome using recursion
 * @start: Pointer to the head of the list
 * @end: Node
 * Return: pointer if it is a palindrome, NULL otherwise
 */
listint_t *palindrome_check(listint_t *start, listint_t *end)
{
	listint_t *temp = NULL;

	if (end)
	{
		temp = palindrome_check(start, end->next);

		if (!temp)
			return (NULL);

		if (temp->n != end->n)
			return (NULL);

		if (!temp->next)
			return (temp);

		return (temp->next);
	}
	return (start);
}
