#include "binary_trees.h"

int binary_tree_balance(const binary_tree_t *tree)
{
    int left, right;

    if (!tree)
        return (0);

    left = (int)binary_tree_height(tree->left);
    right = (int)binary_tree_height(tree->right);

    return (left - right);
}

