#include<stdio.h>
#include<stdlib.h>


void heapify(int arr[], int i, int n);

void buildmaxheap(int arr[], int n);

void heapsort(int arr[], int size)
{	
	int i;
	int temp;
	int j;
	
	buildmaxheap(arr, size);

	
	for (i = size-1; i>1; i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr, 0, i-1);
		
		/**********debugging probe**********
		puts("===================================");
		for (j=0;j<20;j++)
		{
		printf("%3d", arr[j]);
		}
		putchar('\n');
		************************************/

	}
	//swap the first two element and no more heapify
	temp = arr[i];
	arr[i] = arr[0];
	arr[0] = temp;

	
	return;


}
