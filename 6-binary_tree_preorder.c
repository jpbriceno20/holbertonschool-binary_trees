#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);  /* Visit current node */
    binary_tree_preorder(tree->left, func);  /* Recur on left child */
    binary_tree_preorder(tree->right, func); /* Recur on right child */
}

