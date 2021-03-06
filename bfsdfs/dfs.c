#include"queue.h"
#include<stdio.h>

extern int time;

void dfsvisit(ADJNODE * adjlist, VERTEX * parent, ADJNODE * adjlisthead);

void dfs(ADJNODE * adjlist, int id_source, ADJNODE * adjlisthead)
{

	int i;
	VERTEX * current;
	ADJNODE * adjsearch;

	for (i=0;i<12;i++)
	{
		adjsearch = &adjlist[(id_source+i)%12];
		if (adjsearch->self->color == WHITE) //traverse all node in graph
		dfsvisit(adjsearch, NULL, adjlisthead); 
	}

}

void dfsvisit(ADJNODE * adjlist, VERTEX * parent, ADJNODE * adjlisthead)
{
	//printf("current node = %d\n", adjlist->self->id);

	ADJNODE * adjsearch;
	ADJNODE * adjnext;
	time = time + 1; //add 1 when the node first discovered

	adjlist->self->color = GRAY;
	adjlist->self->discover = time;
	adjlist->self->pred = parent;

		
	adjnext = adjlist->next;		
	while (adjnext != NULL)
	{
		if (adjnext->self->color == WHITE)
		{
			adjsearch = &adjlisthead[adjnext->self->id-1];
			dfsvisit(adjsearch, adjlist->self, adjlisthead);
			//if the node was not discovered, search the node in the adjacency list hash table (adjlisthead) and continue the search
		}
		adjnext = adjnext->next;  //search into the link list in adjacency list hash table until reach the end
	}
		

		
	time = time + 1;   //add 1 when the node finished
	adjlist->self->finish = time;
	adjlist->self->color = BLACK;

}
		
