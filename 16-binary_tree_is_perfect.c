#include "binary_trees.h"

/**
 * depth - Measures the depth of the leftmost node
 * @tree: Pointer to the root node
 *
 * Return: Depth value
 */
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

/**
 * is_perfect_recursive - Checks if tree is perfect recursively
 * @tree: Pointer to current node
 * @d: Expected depth
 * @level: Current depth level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t d, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, d, level + 1) &&
		is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d;

	if (tree == NULL)
		return (0);

	d = depth(tree);
	return (is_perfect_recursive(tree, d, 0));
}
