#include<stdio.h>
#include<stdlib.h>

#include"mybst.h"

#define LEN 10

int main()
{

int digi, rootkey;
NODE * root;
NODE * mini; 
NODE * maxi;

int data[LEN] = {40, 60, 30, 70, 22, 36, 35, 67, 1, 99};
int i;

//puts("type root value of the tree:");
//scanf("%d", &rootkey);
root = bstinitialize(50);


for (i=0; i<LEN; i++) bstinsert(root, data[i]);

maxi = bstfindmaxi(root);

mini = bstfindmini(root);

printf("root = %d\n", root->key);
printf("root left = %d\n", root->left->key);
printf("root right = %d\n", root->right->key);
printf("max = %d\n", maxi->key);

printf("min = %d\n", mini->key);


printf("next large = %d\n", nextlarge(root, 30)->key);

printf("next smaller = %d\n", nextsmaller(root, 67)->key);

bstdelete(root, 67);
printf("next smaller = %d\n", nextlarge(root, 60)->key);

return 0;







}
