#include "binary_trees.h"

/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree
* Return: the height of the tree.
*/
int binary_tree_height(const binary_tree_t *tree)
{
	int height, left, right;

	if (tree == NULL)
		return (-1);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left < right)
		height = right + 1;
	else
		height = left + 1;
	return (height);
}

/**
* p_check - runs through a tree checking for perfection
* @tree: pointer to the root node of the tree
* @h: height of the tree
* @l: level of the node
* Return: 1 if the tree is perfect, 0 otherwise
*/
int p_check(const binary_tree_t *tree, int h, int l)
{
	if (tree->left == NULL && tree->right == NULL)
		return (h == l);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (p_check(tree->left, h, l + 1) && p_check(tree->right, h, l + 1));
}

/**
* heap_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree
* Return: 1 if the tree is perfect, 0 otherwise
*/
int heap_is_perfect(const binary_tree_t *tree)
{
	int h, level = 0;

	if (!tree)
		return (0);

	if (binary_tree_height(tree->left) == -1)
		return (1);

	h = binary_tree_height(tree);

	return (p_check(tree, h, level));
}

/**
* heap_checker - checks and ensures max heap property
* @son: pointer to the child node to swap
* @father: pointer to the parent node to swap
* Return: Nothing
*/
void heap_checker(heap_t **son, heap_t **father)
{
	heap_t *c_left, *c_right, *child = *son, *parent = *father;

	c_right = (*son)->right, c_left = (*son)->left;
	if (child->n > parent->n)
	{
		if (child->left)
			child->left->parent = parent;
		if (child->right)
			child->right->parent = parent;
		if (parent->left == child)
		{
			if (parent->right)
				parent->right->parent = child;
			child->right = parent->right;
			child->left = parent;
		}
		else
		{
			parent->left->parent = child;
			child->left = parent->left;
			child->right = parent;
		}
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = child;
			else
				parent->parent->right = child;
		}
		else
		{
			*father = child;
		}

		child->parent = parent->parent;
		parent->parent = child;
		parent->left = c_left;
		parent->right = c_right;
	}
}

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: pointer to the root node of the heap
* @value: the value to be inserted in the heap
* Return: pointer to the inserted node or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (heap_is_perfect(*root) || !heap_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			heap_checker(&((*root)->left), root);
			return (new_node);
		}
		else
		{
			new_node = binary_tree_node(*root, value);
			(*root)->left = new_node;
			heap_checker(&((*root)->left), root);
			return (new_node);
		}
	}
	else
	{
		if ((*root)->right)
		{
			new_node = heap_insert(&((*root)->right), value);
			heap_checker(&((*root)->right), root);
			return (new_node);
		}
		else
		{
			new_node = binary_tree_node(*root, value);
			(*root)->right = new_node;
			heap_checker(&((*root)->right), root);
			return (new_node);
		}
	}
	return (NULL);
}
