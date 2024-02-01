#include "binary_trees.h"

/**
 * count_nodes - helper function to count nodes
 * @tree: pointer to the tree
 * @nodes: number of nodes
 */
void count_nodes(binary_tree_t *tree, size_t *nodes)
{
	if (tree == NULL)
		return;
	if (tree->left || tree->right)
		*nodes += 1;
	count_nodes(tree->left, nodes);
	count_nodes(tree->right, nodes);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	count_nodes((binary_tree_t *)tree, &nodes);
	return (nodes);
}
