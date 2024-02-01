#include "binary_trees.h"

/**
 * count_leaves - counts the leaves in a binary tree
 * @tree: pointer to the tree
 * @leaves: pointer to the count of leaves
 */
void count_leaves(binary_tree_t *tree, size_t *leaves)
{
	if (tree == NULL)
		return;
	if (tree->left == NULL && tree->right == NULL)
		*leaves += 1;
	count_leaves(tree->left, leaves);
	count_leaves(tree->right, leaves);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	count_leaves((binary_tree_t *)tree, &leaves);
	return (leaves);
}
