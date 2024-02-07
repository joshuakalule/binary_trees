#include "binary_trees.h"

/**
 * find - looks for node in tree
 * @tree: pointer to the tree
 * @node: pointer to the node of interest
 * @ans: pointer to a pointer to the return value
 */
void find(binary_tree_t *tree, binary_tree_t *node, binary_tree_t **ans)
{
	if (tree == NULL || node == NULL)
		return;

	if (tree == node)
		*ans = tree;

	/*printf("->%d", tree->n);*/
	if (*ans == NULL)
	{
		find(tree->left, node, ans);
		find(tree->right, node, ans);
	}
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Description:
 * check if second is a child of first
 * check if second is a child of sibling
 * check if second is a child of upper level sibling (uncle) etc
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *node;
	binary_tree_t *ignore = NULL;
	binary_tree_t *ans = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	node = (binary_tree_t *)first;
	while (node != NULL)
	{
		/**
		*if (ignore)
		*	printf("node: %d ignore: %d; ", node->n, ignore->n);
		*else
		*	printf("node: %d ignore: (nil); ", node->n);
		*/
		if (node == second)
		{
			/*printf("\n");*/
			return (node);
		}
		if (node->left != ignore)
			find(node->left, (binary_tree_t *)second, &ans);
		if (node->right != ignore)
			find(node->right, (binary_tree_t *)second, &ans);
		/*printf("\n");*/
		if (ans != NULL)
			return (node);
		ignore = node;
		node = node->parent;
	}
	return (NULL);
}
