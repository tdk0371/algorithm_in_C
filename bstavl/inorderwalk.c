#include"mybst.h"

NODE * bstfindmini(NODE * root);


void inorderwalk(NODE * root)
{
	

if (current->right != NULL)
		return bstfindmini(current->right);
	else
	{
		while ((current->parent != NULL) && (current != current->parent->left))
			current = current->parent;
		return current->parent;
	}
