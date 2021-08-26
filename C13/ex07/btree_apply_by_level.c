#include "ft_btree.h"

void	btree_travel_apply(t_btree *root,
			   void (*applyf)(void *item, int current_level, int is_first_elem),
			   int current, int *depth);

int	btree_level_count(t_btree *root)
{
	int		left;
	int		right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left < right)
		return (right + 1);
	return (left + 1);
}

void	btree_apply_by_level(t_btree *root,
			  void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		a[2];
	int		to_reach;

	a[1] = -1;
	to_reach = btree_level_count(root);
	a[0] = 0;
	while (a[0] < to_reach)
	{
		btree_travel_apply(root, applyf, 0, a);
		a[0] += 1;
	}
}

void	btree_travel_apply(t_btree *root,
			   void (*applyf)(void *item, int current_level, int is_first_elem),
			   int current, int *depth)
{
	if (!root)
		return ;
	if (depth[0] == current)
	{
		if (depth[1] < current)
		{
			applyf(root->item, current, 1);
			depth[1] = current;
		}
		else
			applyf(root->item, current, 0);
		return ;
	}
	btree_travel_apply(root->left, applyf, current + 1, depth);
	btree_travel_apply(root->right, applyf, current + 1, depth);
}
