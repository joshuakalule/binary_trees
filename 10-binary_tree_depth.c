#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *temp_tree;
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	temp_tree = (binary_tree_t *)tree;
	while (temp_tree->parent)
	{
		depth += 1;
		temp_tree = temp_tree->parent;
	}
	return (depth);
}
