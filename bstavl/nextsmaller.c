#include"mybst.h"

NODE * nodesearch(NODE * root, int num);

NODE * bstfindmaxi(NODE * root);


NODE * nextsmaller(NODE * root, int num)
{
	NODE * current;
	if (nodesearch(root, num) == NULL)
		return NULL;
	else
		current = nodesearch(root, num);
	
	if (current->left != NULL)
		return bstfindmaxi(current->left);
	else
	{
		while ((current->parent != NULL) && (current != current->parent->right))
			current = current->parent;
		return current->parent;
	}



}
