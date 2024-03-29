#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node
 * Return: pointer to the uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle, *parent, *grand_parent;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == NULL)
		return (NULL);

	grand_parent = node->parent->parent;
	if (grand_parent == NULL)
		return (NULL);

	if (grand_parent->left == parent)
		uncle = grand_parent->right;
	else
		uncle = grand_parent->left;

	return (uncle);
}
