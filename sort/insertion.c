#include<stdlib.h>
#include<stdio.h>

void insertion(int arr[], int len)
{
	int i, j;
	int temp;
	//int count;
	
	for (i=0;i<len-1;i++)
	{
		//count = 0;
		j = i+1;
		while ((j>0) && (arr[j]<arr[j-1]))  //remember add j>0, otherwise some strange number in the memory will be added into comparison
		{
			temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
			//count++;
		}
		//printf("count = %d\n", count);
	}
}
		
