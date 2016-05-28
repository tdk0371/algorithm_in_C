#include"mybst.h"

NODE * nodesearch(NODE * root, int num);

NODE * bstfindmini(NODE * root);


NODE * nextlarge(NODE * root, int num)
{
	NODE * current;
	if (nodesearch(root, num) == NULL)
		return NULL;
	else
		current = nodesearch(root, num);
	
	if (current->right != NULL)
		return bstfindmini(current->right);
	else
	{
		while ((current->parent != NULL) && (current != current->parent->left))
			current = current->parent;
		return current->parent;
	}



}
