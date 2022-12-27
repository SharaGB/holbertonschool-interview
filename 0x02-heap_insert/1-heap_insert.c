#include "binary_trees.h"
/**
 *binary_tree_size - depth
 *@tree: tree.
 *Return: size the add between depths
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t depthl = 0;
	size_t depthr = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		depthl = binary_tree_size(tree->left);
		depthr = binary_tree_size(tree->right);
		return ((depthl + depthr) + 1);
	}
}

/**
 * inipoint - initial point
 * @star: where it start
 * Return: to root
 */
heap_t *inipoint(heap_t *star)
{
	int n_tmp = 0;

	if (!star->parent || !star)
		return (star);

	while (star->parent)
	{
		if (star->n < star->parent->n)
		{
			return (star);
		}
		n_tmp = star->n;
		star->n = star->parent->n;
		star->parent->n = n_tmp;
		star = star->parent;
	}
	return (star);
}

/**
 * heap_insert - insert
 * @root: double pointer to head
 * @value: value to be inserted
 * Return: 0 on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int tmp_mk = 0;
	int idx_b = 0;
	ssize_t size_t = (1 + binary_tree_size(*root));
	heap_t *tmp_node = *root;
	heap_t *tmp_n_node = NULL;

	tmp_n_node = binary_tree_node(tmp_node, value);
	if (!tmp_n_node)
	{
		return (NULL);
	}
	if (!*root)
	{
		return (*root = tmp_n_node);
	}
	for (;;)
	{
		if (1 << (idx_b + 1) > size_t)
			break;
		idx_b++;
	}
	idx_b--;
	for (; idx_b > 0; idx_b--)
	{
		tmp_mk = (1 << idx_b);
		if (size_t & tmp_mk)
		{
			tmp_node = tmp_node->right;
		}
		else
		{
			tmp_node = tmp_node->left;
		}
	}
	if (size_t & 1)
		tmp_node->right = tmp_n_node;
	else
		tmp_node->left = tmp_n_node;
	tmp_n_node->parent = tmp_node;
	return (inipoint(tmp_n_node));
}
