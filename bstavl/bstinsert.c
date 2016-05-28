#include"mybst.h"

void bstinsert(NODE * root, int num)
{
	if (num < root->key)
	{
		if (root->left == NULL)
		{
			NODE * newnode = (NODE *)malloc(sizeof(NODE));
			root->left = newnode;
			newnode->parent = root;
			newnode->left = NULL;
			newnode->right= NULL;
			newnode->key  = num;
			newnode->height = 0;
			return;
		}
		else
			bstinsert(root->left, num);
	}
	else
	{
		if (root->right == NULL)
		{
			NODE * newnode = (NODE *)malloc(sizeof(NODE));
			root->right = newnode;
			newnode->parent = root;
			newnode->left = NULL;
			newnode->right= NULL;
			newnode->key  = num;
			newnode->height = 0;
			return;
		}
		else
			bstinsert(root->right, num);
	}			
	
}
