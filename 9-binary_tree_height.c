#include "binary_trees.h"

/**
 * get_height - helper function to signed height.
 * @tree: pointer to the tree to measure
 * Return: signed size
 */
ssize_t get_height(const binary_tree_t *tree)
{
	ssize_t lh = 0, rh = 0;

	if (tree == NULL)
		return (-1);
	lh = get_height(tree->left);
	rh = get_height(tree->right);

	if (lh > rh)
		return (lh + 1);
	else
		return (rh + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	ssize_t h;

	if (tree == NULL)
		return (0);
	h = get_height(tree);
	if (h < 0)
		return (0);
	else
		return ((size_t) h);
}
