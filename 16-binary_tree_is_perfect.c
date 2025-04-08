#include "binary_trees.h"

size_t depth(const binary_tree_t *tree)
{
    size_t d = 0;
    while (tree)
    {
        d++;
        tree = tree->left;
    }
    return (d);
}

int is_perfect(const binary_tree_t *tree, size_t d, size_t level)
{
    if (!tree)
        return (1);
    if (!tree->left && !tree->right)
        return (d == level + 1);
    if (!tree->left || !tree->right)
        return (0);
    return (is_perfect(tree->left, d, level + 1) && is_perfect(tree->right, d, level + 1));
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t d;

    if (!tree)
        return (0);

    d = depth(tree);
    return (is_perfect(tree, d, 0));
}

