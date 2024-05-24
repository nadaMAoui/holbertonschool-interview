#include "binary_trees.h"

/**
 * sorted_array_to_avl -function that builds an AVL tree from an array
 * @array: array
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree, or NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || size <= 0)
		return (NULL);

	tree = add_node(0, NULL, size - 1, array);
	return (tree);
}

/**
 * add_node - create tree
 * @array: array
 * @s: start node
 * @f: final node
 * @parent: parent node
 * Return: pointeur(mean true)
 */
avl_t *add_node(size_t s, avl_t *parent, size_t f, int *array)
{
	size_t m;
	avl_t *tree;

	if (s > f)
		return (NULL);

	m = (s + f) / 2;
	tree = new_node(parent, array[m]);
	if (!tree)
		return (NULL);

	if (m != f)
		tree->right = add_node(m + 1, tree, f, array);

	if (m != s)
		tree->left = add_node(s, tree, m - 1, array);

	return (tree);
}

/**
 * new_node - create new node
 * @p: parent node
 * @n: data
 * Return: node
 */
avl_t *new_node(avl_t *p, size_t n)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->right = NULL;
	new->parent = p;
	new->left = NULL;
	return (new);
}
