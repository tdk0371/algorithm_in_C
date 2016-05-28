#include<stdio.h>
#include<stdlib.h>
#include<time.h>



#define LEN 11

int mycomp(const void * p1, const void *p2);
void showarray(const double (*)[LEN]);
void peak1(const double (*)[LEN]);
void peak2(const double (*)[LEN], int , int);

int main()
{
	double data[LEN][LEN];
	double cdata[11][11]= { 
	{ 4.1,  5.1,  6.1,  7.1,  8.1,  7.1,  6.1,  5.1,  4.1,  3.1,  2.1},
	{ 5.0,  6.1,  7.1,  8.1,  9.1,  8.1,  7.1,  6.1,  5.1,  4.1,  3.1},
	{ 6.0,  7.1,  8.1,  9.1, 10.1,  9.1,  8.1,  7.1,  6.1,  5.1,  4.1},
	{ 7.0,  8.1,  9.1, 10.1, 11.1, 10.1,  9.1,  8.1,  7.1,  6.1,  5.1},
	{ 8.1,  9.1, 10.1, 11.1, 12.1, 11.1, 10.1,  9.1,  8.1,  7.1,  6.1},
	{ 7.1,  8.2,  9.2, 10.2, 11.2, 10.1,  9.2,  8.1,  7.2,  6.1,  5.1},
	{ 6.1,  7.2,  8.1,  9.1, 10.1,  9.1,  8.1,  7.1,  6.2,  5.3,  4.1},
	{ 5.1,  6.2,  7.3,  8.2,  9.1,  8.2,  7.1,  6.3,  5.1,  4.2,  3.3},
	{ 4.1,  5.3,  6.1,  7.2,  8.1,  7.3,  6.1,  5.2,  4.1,  3.1,  2.1},
	{ 3.1,  4.3,  5.1,  6.1,  7.3,  6.1,  5.1,  4.1,  3.3,  2.1,  1.1},
	{ 2.1,  3.3,  4.1,  5.1,  6.1,  5.1,  4.3,  3.1,  2.1,  1.1,  0.1}};

	int ir, ic;
	srand((unsigned int) time(0));   //reset seed
	for (ir=0; ir<LEN; ir++)
	{
		for(ic=0; ic<LEN; ic++)
			//data[ir][ic] = data[ir][ic-1]+1; 
			data[ir][ic] = ((double) rand()+1.0)/((double) rand());

	}

	//data[666][666] = 9999999;  //sometimes peak2 cannot find peak

	//qsort(data, LEN, sizeof(double), mycomp);
	showarray(data);


	long int start1, end1;
	start1 = clock();
	peak1(cdata);
	end1 = clock();
	printf("run time for peak1: %ldms\n", end1-start1);

	long int start2, end2;
	start2 = clock();
	peak2(cdata, 0, LEN);
	end2 = clock();
	printf("run time for peak2: %ldms\n", end2-start2);


return 0;


}



void peak1(const double (*data)[LEN])
{
	int ic, ir;
	for (ir=0; ir<LEN; ir++)
	{
		for(ic=0; ic<LEN; ic++)
			if (data[ir][ic]>data[ir-1][ic] && data[ir][ic]>data[ir+1][ic] && data[ir][ic]>data[ir][ic-1] && data[ir][ic]>data[ir][ic+1]) //need to add more if statement to confine the comparison within the edge of matrix, to avoid comparison with memory outside of matrix
			{			
				printf("peak found at (%d, %d) = %8.3f\n", ir, ic, data[ir][ic]);			return;
			}
			
		
	}



}


void peak2(const double (*data)[LEN], int startc, int endc)
{
	//puts("recursence+1");
	int ir, irm;
	double max = data[0][(endc+startc)/2];
	for (ir=0; ir<LEN; ir++)
	{
		if (data[ir][(endc+startc)/2]>max)
		{
			max = data[ir][(endc+startc)/2];
			irm=ir;
		}
		
	}
	printf("max in line : %8.2f\n", data[irm][(endc+startc)/2]);
	if (data[irm][(endc+startc)/2]>data[irm][(endc+startc)/2-1] && data[irm][(endc+startc)/2]>data[irm][(endc+startc)/2+1])
	{
		printf("peak found at (%d, %d) = %8.3f\n", irm, (endc+startc)/2, data[irm][(endc+startc)/2]);
		return;
	}
	else if ((endc>LEN) ||(startc<0))
	{
		printf("peak not found\n");
		return;
	}
	else if (data[irm][(endc+startc)/2]<=data[irm][(endc+startc)/2-1] && data[irm][(endc+startc)/2]>data[irm][(endc+startc)/2+1]  )  //go left side
	{
		peak2(data, startc, (startc+endc)/2);
		//puts("lll");
	}
	
	else  //go right side
	{
		peak2(data, (startc+endc)/2, endc);
		//puts("rrr");
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


void showarray(const double (*ar)[LEN])
{	
	int ir, ic;
	puts("====================array data======================");
	for (ir=0; ir<LEN; ir++)
	{
		for(ic=0; ic<LEN; ic++)
			printf("%8.2f", ar[ir][ic]);
		putchar('\n');
	}
	putchar('\n');

}





		
