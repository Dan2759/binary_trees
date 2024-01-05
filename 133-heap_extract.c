#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t left_cmp = 0;
	size_t right_cmp = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_cmp = 1 + tree_height(tree->left);

	if (tree->right)
		right_cmp = 1 + tree_height(tree->right);

	if (left_cmp > right_cmp)
		return (left_cmp);
	return (right_cmp);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t left_cmp = 0;
	size_t right_cmp = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_cmp = 1 + tree_size_h(tree->left);

	if (tree->right)
		right_cmp = 1 + tree_size_h(tree->right);

	return (left_cmp + right_cmp);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last, *node;

	if (!root || !*root)
		return (0);
	last = *root;
	value = last->n;
	if (!last->left && !last->right)
	{
		*root = NULL;
		free(last);
		return (value);
	}

	_preorder(last, &node, tree_height(last));

	last->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(last);
	*root = last;
	return (value);
}
