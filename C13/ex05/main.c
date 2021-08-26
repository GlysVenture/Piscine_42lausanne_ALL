//
// Created by Mano Segransan on 8/23/21.
//
#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_apply_prefix(t_btree *root, void(*applyf)(void*));

void	ft_putnbr(void *nb)
{
	printf("%d\n", *((int *)nb));
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = malloc(sizeof(t_btree));
	elem->item = item;
	elem->left = NULL;
	elem->right = NULL;
	return (elem);
}

int comp(void *nb, void *cp)
{
	return (*(int *)nb != *(int *)cp);
}

void	btree_apply_infix(t_btree *root, void(*applyf)(void*))
{
	if (root == NULL)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}

void	btree_insert_data_rec(t_btree *root, void *item,
							  int(*cmpf)(void*, void*))
{
	if (cmpf(root->item, item) > 0)
	{
		if (root->left != NULL)
			btree_insert_data_rec(root->left, item, cmpf);
		else
			root->left = btree_create_node(item);
	}
	else
	{
		if (root->right != NULL)
			btree_insert_data_rec(root->right, item, cmpf);
		else
			root->right = btree_create_node(item);
	}
}

void	btree_insert_data(t_btree **root, void *item, int(*cmpf)(void*, void*))
{
	t_btree	*elem;

	elem = *root;
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(elem->item, item) > 0)
	{
		if (elem->left != NULL)
			btree_insert_data_rec(elem->left, item, cmpf);
		else
			elem->left = btree_create_node(item);
	}
	else
	{
		if (elem->right != NULL)
			btree_insert_data_rec(elem->right, item, cmpf);
		else
			elem->right = btree_create_node(item);
	}
}

int cc(void *nb, void *cp)
{
	return (*(int *)nb - *(int *)cp);
}

void	*btree_search_item(t_btree *root, void *data_ref, int(*cmpf)(void*,void*));

int main(void)
{
	t_btree *t;
	int a = 8;
	int b = 3;
	int c = 10;
	int d = 13;
	int e = 3;
	void	*out;

	t = btree_create_node(&a);
	t->left = btree_create_node(&b);
	t->right = btree_create_node(&c);
	btree_insert_data(&t, &d, cc);
	btree_apply_infix(t, ft_putnbr);
	printf("\n");
	out = btree_search_item(t, &e, comp);
	ft_putnbr(out);
	printf("\n");
}
