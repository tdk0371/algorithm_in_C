//#include<stdio.h>

void heapify(int arr[], int i, int n)
{
int j;

	int temp;
	if (2*i+1 == n)  //avoid memory leakage when one node only has one leaf
	{
		if (arr[i]<arr[2*i+1])
		{
			temp = arr[i];
			arr[i] = arr[2*i+1];
			arr[2*i+1] = temp;

			/****debugging probe********
			puts("===================================");
			for (j=0;j<20;j++)
			{
				printf("%3d", arr[j]);
			}
			putchar('\n');
			**********************/
			return;
		}
		else
		{
			/*******debugging probe*******
			puts("===================================");
			for (j=0;j<20;j++)
			{
				printf("%3d", arr[j]);
			}	
			putchar('\n');
			*****************************/
		
			return;
		}
	}

	if (arr[i]>=arr[2*i+1] && arr[i]>=arr[2*i+2])
		return;
	else if (arr[i]<arr[2*i+1] && arr[2*i+1]>=arr[2*i+2])
	{
		temp = arr[i];
		arr[i] = arr[2*i+1];
		arr[2*i+1] = temp;
		if (2*(2*i+1)<n)      //stop searching if no leaf
		heapify(arr, 2*i+1, n);
	}
	else 
	{
		temp = arr[i];
		arr[i] = arr[2*i+2];
		arr[2*i+2] = temp;
		if (2*(2*i+2)<n)  //stop recursion if no leaf
		heapify(arr, 2*i+2, n);
	}
	
	/******debuging probe********
	puts("===================================");
		for (j=0;j<20;j++)
		{
		printf("%3d", arr[j]);
		}
		putchar('\n');
	******************/

}
