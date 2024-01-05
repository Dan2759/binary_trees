#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lh = 0, rh = 0;

		lh = tree->left ? 1 + height(tree->left) : 1;
		rh = tree->right ? 1 + height(tree->right) : 1;
		return ((lh > rh) ? lh : rh);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree
 * @lo: The value of the smallest node visited this far
 * @hi: The value of the largest node visited this far
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t l, r, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		l = height(tree->left);
		r = height(tree->right);
		diff = l > r ? l - r : r - l;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
