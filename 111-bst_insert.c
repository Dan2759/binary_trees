#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new_node;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new_node = binary_tree_node(curr, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}

		if (value < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new_node = binary_tree_node(curr, value);
			if (new_node == NULL)
				return (NULL);
			return (curr->left = new_node);
		}
		if (value > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new_node = binary_tree_node(curr, value);
			if (new_node == NULL)
				return (NULL);
			return (curr->right = new_node);
		}
	}
	return (NULL);
}
