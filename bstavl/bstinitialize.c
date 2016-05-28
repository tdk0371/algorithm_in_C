#include"mybst.h"

NODE * bstinitialize(int num)
{
	NODE * root = (NODE *)malloc(sizeof(NODE));
	root->key = num;
	root->height = 0;
	root->parent = NULL;
	root->left = NULL;
	root->left = NULL;
	return root;


}
