#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>

/**
* struct binary_tree_s - Binary tree node
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/
typedef struct binary_tree_s
{
	int n;

	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

int binary_tree_height(const binary_tree_t *tree);
int p_check(const binary_tree_t *tree, int h, int l);

int heap_is_perfect(const binary_tree_t *tree);
void heap_checker(heap_t **son, heap_t **father);
heap_t *heap_insert(heap_t **root, int value);

#endif /* _BINARY_TREES_H_ */
