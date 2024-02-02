#include "binary_trees.h"

/**
 * get_height - helper function to signed height
 * @tree: pointer to the tree to measure
 * Return: signed size
 */
ssize_t get_height(const binary_tree_t *tree)
{
	ssize_t lh = 0, rh = 0;

	if (tree == NULL)
		return (0);
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

/**
 * check_tree - helper function to check if a tree is perfect
 * @tree: pointer to tree
 * @ans: 1 (PERFECT) 0 (NOT PERFECT)
 */
void check_tree(binary_tree_t *tree, int *ans)
{
	size_t lh = 0, rh = 0;

	if (tree == NULL)
		return;
	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	if (rh != lh)
		*ans = 0;
	if (tree->left == NULL && tree->right != NULL)
		*ans = 0;
	if (tree->left != NULL && tree->right == NULL)
		*ans = 0;
	/*printf("[%d]: rh %ld, lh %ld\n", tree->n, rh, lh);*/
	check_tree(tree->left, ans);
	check_tree(tree->right, ans);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 (PERFECT) 0 (NOT PERFECT)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int ans = 1;

	if (tree == NULL)
		return (0);

	check_tree((binary_tree_t *)tree, &ans);
	return (ans);
}
