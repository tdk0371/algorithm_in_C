/****************************
MERGE SORT RECURSION ROUTINE

MERGE-SORT( A, p, q, r):
	MERGE-SORT(A, p, q)
	MERGE-SORT(A, q, r)
	MERGE
****************************/
#include<stdlib.h>
#include<stdio.h>

int * mergesort(const int *start, const int *end) //days of debug result: remember to make start=data, end=data+size-1, it is +(size-1), not (size), or you run in error
{
	
	//divide
	const int *mid;
	mid = (start+(end-start)/2);   //(start+end)/2 is invalid here
	int *left, *right;
	printf("head: start at %p, mid at %p, end at %p\n", start, mid, end);
	if (start<end)
	{
		//puts("recursion if +1");
		left = mergesort(start, mid);
		right = mergesort(mid+1, end);
	}
	else
	{
		//puts("recursion else +1");
		int * sorted = (int *)malloc(1);
		* sorted = * end;   //pass value not address: sorted = start
		printf("leaves sorted = %d at %p\n", *sorted, sorted);
		return sorted;
	}
	
	
	
	//merge
	int * sorted = (int *)malloc(end-start+1);
	int max = (end-start+1);
	int count = 0, il = 0, ir = 0;
	printf("max count = %d\n", max);
	printf("start at %p, end at %p\n", start, end);
	while (count<max)
	{
		printf("count = %d, ir = %d, right[ir]= %d il = %d, left[il] = %d\n", count, ir, right[ir], il, left[il]);
		if (il >= max/2)
		{
			puts("a");
			sorted[count] = right[ir];
			ir++;
			count++;
			continue;
		}
		else if (ir >= max/2)
		{
			puts("b");
			sorted[count] = left[il];
			il++;
			count++;
			continue;
		}
		else if (left[il]<=right[ir])
		{
			puts("c");
			sorted[count] = left[il];
			il++;
			count++;
		}
		else
		{
			puts("d");
			sorted[count] = right[ir];
			ir++;
			count++;
		}
	//printf("count = %d, ir = %d, right[ir]= %d il = %d, left[il] = %d\n", count, ir, right[ir], il, left[il]);
	}
	//free(left);
	//free(right);
	int i;
	for (i=0;i<count;i++)
	{
	printf("sorted %d = %d\n", i, sorted[i]);
	}
	return sorted;
	
}


