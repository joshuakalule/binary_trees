#include "binary_trees.h"

/**
 * count_trees - helper to measures the size of a binary tree
 * @tree: pointer to the tree to measure
 * @size: pointer to the size variable
 */
void count_trees(binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
		return;
	*size += 1;
	count_trees(tree->left, size);
	count_trees(tree->right, size);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);
	size = 1;
	count_trees(tree->left, &size);
	count_trees(tree->right, &size);
	return (size);
}
