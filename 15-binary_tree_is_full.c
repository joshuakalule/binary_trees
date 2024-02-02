#include "binary_trees.h"

/**
 * check_tree - helper to check if a tree is full
 * @tree: pointer to tree
 * @ans: 1 (FULL) 0 (OTHERWISE)
 */
void check_tree(binary_tree_t *tree, int *ans)
{
	if (tree == NULL)
		return;

	if (tree->left == NULL && tree->right != NULL)
		*ans = 0;

	if (tree->left != NULL && tree->right == NULL)
		*ans = 0;

	check_tree(tree->left, ans);
	check_tree(tree->right, ans);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 (TRUE) 0 (OTHERWISE)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int ans = 1;

	if (tree == NULL)
		return (0);

	check_tree((binary_tree_t *)tree, &ans);
	return (ans);
}
