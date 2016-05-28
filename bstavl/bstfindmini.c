#include"mybst.h"

NODE * bstfindmini(NODE * root)
{
	if (root->left != NULL)
		return bstfindmini(root->left);
	else 
		return root;
}
