#include"queue.h"


extern void relax(ADJNODE * node1, ADJNODE * node2);

VERTEX * extractmin(QUEUE * thequeue); 
//the queue used here is just a copy from BFS queue, not a good queue for Dijkstra
//it is not convenient to delete min node in the middle of queue


void dijkstra(ADJNODE * adjlist, int source, int total)
{

int i;
QUEUE * thequeue;
thequeue = ini_queue();
VERTEX * current;
ADJNODE * adjsearch;

for (i=0;i<total;i++) en_queue(thequeue, adjlist[i].self);

adjlist[source].self->distance = 0;

while (thequeue->head != NULL)
{
	current = extractmin(thequeue); //extract min distance vertice out from queue
	adjsearch = adjlist[(current->id)-1].next;  //refer back to adj list head

	while (adjsearch != NULL)
	{
		relax(&adjlist[(current->id)-1], adjsearch);
		adjsearch = adjsearch->next;
	}

	//for (i=0;i<total;i++)
	//printf("in vertex %3d the distance is %3d\n", (adjlist[i].self->id), adjlist[i].self->distance);
}

}


VERTEX * extractmin(QUEUE * thequeue)
{
	VERTEX * minv;
	VERTEX * minvp;   //the node befor minv
	VERTEX * prev;    //store nextv before nextv = nextv->next
	VERTEX * nextv;
	minv = thequeue->head;
	nextv = thequeue->head->next;
	prev = thequeue->head;

	while (nextv != NULL)
	{
		if (minv->distance > nextv->distance)	
		{
			minvp = prev;   //node before minv node		
			minv = nextv;   //the min node
		}
		prev = nextv;
		nextv = nextv->next;
	}

	if (minv == thequeue->head)
	{
		thequeue->head = thequeue->head->next;
		return minv;
	}
	else
	{
		minvp->next = minv->next;  //delete minv from linked list
		return minv;
	}	


}
