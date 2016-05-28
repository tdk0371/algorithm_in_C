#include<stdio.h>
#include<stdlib.h>
#include<time.h>



#define LEN 100000

int mycomp(const void * p1, const void *p2);
void showarray(const double *);
void peak1(const double *);
void peak2(const double *start, const double *end);

int main()
{
	double data[LEN];
	double cdata[LEN]= {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 7.7, 1.1};

	int index;
	srand((unsigned int) time(0));   //reset seed
	for (index=0; index<LEN; index++)
	{
		data[index] = ((double) rand()+1.0)/((double) rand());

	}

	qsort(data, LEN, sizeof(double), mycomp);
	showarray(data);


	long int start1, end1;
	start1 = clock();
	peak1(data);
	end1 = clock();
	printf("run time for peak1: %ldms\n", end1-start1);

	long int start2, end2;
	start2 = clock();
	peak2(data, data+LEN);
	end2 = clock();
	printf("run time for peak2: %ldms\n", end2-start2);


return 0;


}



void peak1(const double *data)
{
	int i = 1;
	for (i; i<(LEN); i++)
	{
		if (data[i]>data[i-1] && data[i]>data[i+1])
		{	
			printf("find the peak at %d\n", i);
			return;
		}
	}

}

void peak2(const double *start, const double *end)
{


	//printf("%f", *(start+(end-start)/2));
	//static double * const head = start;

	if ((*(start+(end-start)/2))>(*(start+(end-start)/2-1)) && (*(start+(end-start)/2))>(*(start+(end-start)/2+1)))
	{
		printf("peak at %f\n", *(start+(end-start)/2)/*(((start+(end-start)/2))-head)/sizeof(double)*/);
		return;
	}
	else if ((*(start+(end-start)/2))>(*(start+(end-start)/2-1)) && (*(start+(end-start)/2))<=(*(start+(end-start)/2+1)))  //go right side
	{
		peak2((start+(end-start)/2), end);
	}
	else   //go left side
	{
		peak2(start, (start+(end-start)/2));
	}
}
	


int mycomp(const void * p1, const void *p2)
{
	const double * x1 = (const double *) p1;  
	const double * x2 = (const double *) p2;
	//typecast for pointer, required by C++ but optinal for C

	if (*x1 > *x2)
		return 1;
	else if (*x1 == *x2)
		return 0;
	else 
		return -1;
}


void showarray(const double * ar)
{	
	puts("====================array data======================");
	int i;
	for (i=0; i<LEN; i++)
	{	printf("%8.3f", ar[i]);
		if (i%5 == 0)
			putchar('\n');
	}
	putchar('\n');
	putchar('\n');

}





		
