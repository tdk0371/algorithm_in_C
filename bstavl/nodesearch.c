#include"mybst.h"

NODE * nodesearch(NODE * root, int num)
{
	if (num == root->key)
		return root;
	else if (num >= root->key)
	{	
		if (root -> right == NULL)
			return NULL;
		else
			return nodesearch( root->right, num);
	}
	else 
	{
		if (root -> left == NULL)
			return NULL;
		else
			return nodesearch(root->left, num);
	}
}
