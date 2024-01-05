#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t left_cmp = 0;
	size_t right_cmp = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_cmp = 1 + tree_size(tree->left);

	if (tree->right)
		right_cmp = 1 + tree_size(tree->right);

	return (left_cmp + right_cmp);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to the root node of the heap
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *sorted = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	sorted = malloc(sizeof(int) * (*size));

	if (!sorted)
		return (NULL);

	for (i = 0; heap; i++)
		sorted[i] = heap_extract(&heap);

	return (sorted);
}
