#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new = tree->left;
	temp = new->right;
	new->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = new;
	new->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = new;
		else
			temp->right = new;
	}

	return (new);
}
