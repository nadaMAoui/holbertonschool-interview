#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Structure definition for a tree node
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent; // Added parent pointer for efficient heap operations
} treeNode_t;

// Function prototypes
void max_heapify(treeNode_t *root);
int get_num_nodes(treeNode_t *root);
treeNode_t *get_last_node(treeNode_t *root);
int heap_extract_max(treeNode_t **root);

#endif
