#include "binary_trees.h"

/**
* binary_tree_node - function that creates a binary tree node
* @parent: pointer to the parent node of the node to create.
* @value: value to put in the new node
* Return: a pointer to the newly created node or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	if (!parent)
		return (new);

	if (!(parent->left))
		parent->left = new;
	else
		parent->right = new;

	return (new);
}
