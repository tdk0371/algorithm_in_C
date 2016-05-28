
#include"sort.h"
#include<time.h>
#include<string.h>

#define LEN 2000


int main()
{
	int data[10] = {1, 3, 4, 2, 6, 5,8,7,9, 10};
	int * sorted;
	int rdata[LEN];
	int i = 0;
	int index;
	srand((unsigned int) time(0));
	for (index=0; index<LEN; index++)
	{
		rdata[index] = (rand()%200);

	}
	/*puts("===================================");
	for (i=0;i<LEN;i++)
	{
		printf("%d\n", rdata[i]);
	}*/






	int rdata1[LEN];
	memcpy(rdata1, rdata, LEN*sizeof(int));

	
	int rdata2[LEN];
	memcpy(rdata2, rdata, LEN*sizeof(int));
	






	long int start1, start2, end1, end2, start3, end3;

	start1 = clock();
	insertion(rdata, LEN);
	end1 = clock();

	start2 = clock();
	mergeSort2(rdata1, 0, LEN-1);
	end2 = clock();

	start3 = clock();
	heapsort(rdata2, LEN);
	end3 = clock();



	puts("==============rdata=====================");
	for (i=0;i<LEN;i++)
	{
		printf("%6d", rdata2[i]);
	}
	putchar('\n');

	printf("runtime-insertion sort: %ldms\n", end1-start1);  //O(n*n)

	printf("runtime-merge sort: %ldms\n", end2-start2); //O(nlgn)

	printf("runtime-heap sort: %ldms\n", end3-start3);  //O(nlgn)





/*
puts("==============rdata=====================");
for (i=0;i<LEN;i++)
	{
		printf("%4d", rdata[i]);
	}
putchar('\n');
*/

return 0;
}
