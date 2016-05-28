#include"mybst.h"


NODE * bstfindmini(NODE * root);
NODE * nodesearch(NODE * root, int num);

void bstdelete(NODE * root, int num)
{
	NODE * todelete;
	todelete = nodesearch(root, num);
	if (todelete == NULL)
		return;

	if ((todelete->left == NULL) && (todelete->right == NULL))
	{
		if (todelete->parent->left == todelete)
		{
			todelete->parent->left = NULL;
			free(todelete);
			return;
		}	
		if (todelete->parent->right == todelete)
		{
			todelete->parent->right = NULL;
			free(todelete);
			return;
		}	
	}
	if ((todelete->left == NULL) && (todelete->right != NULL))
	{
		if (todelete->parent->left == todelete)
		{
			todelete->parent->left = todelete->right;
			todelete->right->parent = todelete->parent;
			free(todelete);
			return;
		}	
		if (todelete->parent->right == todelete)
		{
			todelete->parent->right = todelete->right;
			todelete->right->parent = todelete->parent;
			free(todelete);
			return;
		}	
	}
	if ((todelete->left != NULL) && (todelete->right == NULL))
	{
		if (todelete->parent->left == todelete)
		{
			todelete->parent->left = todelete->left;
			todelete->left->parent = todelete->parent;
			free(todelete);
			return;
		}	
		if (todelete->parent->right == todelete)
		{
			todelete->parent->right = todelete->left;
			todelete->left->parent = todelete->parent;
			free(todelete);
			return;
		}	
	}
	if ((todelete->left != NULL) && (todelete->right != NULL))
	{
		
		//swap the node key with next large node key, then swap pointer
		todelete->key = bstfindmini(todelete->right)->key;
		
		todelete = bstfindmini(todelete->right);
		
		//following code is a copy of previous part of bstdelete to delete 			the previous next large node
		
		if ((todelete->left == NULL) && (todelete->right == NULL))
		{
			if (todelete->parent->left == todelete)
			{
				todelete->parent->left = NULL;
				free(todelete);
				return;
			}	
			if (todelete->parent->right == todelete)
			{
				todelete->parent->right = NULL;
				free(todelete);
				return;
			}	
		}
		if ((todelete->left == NULL) && (todelete->right != NULL))
		{
			if (todelete->parent->left == todelete)
			{
				todelete->parent->left = todelete->right;
				todelete->right->parent = todelete->parent;
				free(todelete);
				return;
			}	
			if (todelete->parent->right == todelete)
			{
				todelete->parent->right = todelete->right;
				todelete->right->parent = todelete->parent;
				free(todelete);
				return;
			}	
		}
		if ((todelete->left != NULL) && (todelete->right == NULL))
		{
			if (todelete->parent->left == todelete)
			{
				todelete->parent->left = todelete->left;
				todelete->left->parent = todelete->parent;
				free(todelete);
				return;
			}	
			if (todelete->parent->right == todelete)
			{
				todelete->parent->right = todelete->left;
				todelete->left->parent = todelete->parent;
				free(todelete);
				return;
			}	
		}







	}


}
