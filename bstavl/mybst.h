#ifndef MYBST_H_
#define MYBST_H_


typedef struct node {
			int height;
			int key;
			struct node * parent;
			struct node * left;
			struct node * right;} NODE;

//initialize a bst
NODE * bstinitialize(int num);

//find a number in the bst
NODE * nodesearch(NODE * root, int num);

//find the minimum in the tree
NODE * bstfindmini(NODE * root);

//find the maximum in the tree
NODE * bstfindmaxi(NODE * root);

//find next number larger than num in the tree
NODE * nextlarge(NODE * root, int num);

//find next number smaller than num in the tree
NODE * nextsmaller(NODE * root, int num);

//insert node into bst
void bstinsert(NODE * root, int num);

//delete a number in the bst
void bstdelete(NODE * root, int num);

//update height of node
void updateh(NODE * root);

//check if bst enpty
void bstempty(NODE * root);

//check if bst full
void bstfull(NODE * root);

//print node in order
void inorderwalk(NODE * root);


#endif
