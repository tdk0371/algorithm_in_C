#include"queue.h"



void relax(ADJNODE * node1, ADJNODE * node2);

void bellman(ADJNODE * adjlist, int source, int total)
{

int i;
int j;
int k;
int index;
ADJNODE * adjsearch;

adjlist[source].self->distance = 0;


for (i=0;i<total-1;i++)  //run V-1 times
{
	for (j=0;j<total;j++)   //relax all edges in each run
	{
		//index = (source+j)%total;  //not necessary to start from source
		index = j;
		adjsearch = adjlist[index].next;
		while (adjsearch != NULL)
		{
			relax(&adjlist[index], adjsearch);
			adjsearch = adjsearch->next;
		}
	
	}

//for (k=0;k<total;k++)
//printf("in vertex %3d the distance is %3d\n", (adjlist[k].self->id), adjlist[k].self->distance);

//putchar('\n');
}



for (i=0;i<total;i++)   //negative loop check
{
	
	adjsearch = adjlist[i].next;
	while (adjsearch != NULL)
	{
		//printf("adjsearch = %3d, adjlist = %3d, weight = %3d\n", adjsearch->self->distance, adjlist[i].self->distance, adjsearch->weight);
		//printf("i = %d\n",i);

		if (adjsearch->self->distance > adjlist[i].self->distance + adjsearch->weight) 
		{
			printf("negative loop exist\n");
			return;
		}
		adjsearch = adjsearch->next;
	}

}


}



void relax(ADJNODE * node1, ADJNODE * node2)
{
	if (node2->self->distance > node1->self->distance + node2->weight)
	{
		node2->self->distance = node1->self->distance + node2->weight;
		node2->self->pred = node1->self;
	}

}
