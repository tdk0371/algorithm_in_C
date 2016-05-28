#include"mybst.h"

NODE * bstfindmaxi(NODE * root)
{
	if (root->right != NULL)
		return bstfindmaxi(root->right);
	else 
		return root;

}
