#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int * test();


int main()
{

	int * arr;
	int b;
	b = 1/0;

	arr=test();

	printf("%d", arr[1]);

	return 0;

}


int * test()
{
	int * pt = (int *)malloc(5*sizeof(int));
	pt[0] = 1;
	pt[1] = 2;

	return pt;
}
