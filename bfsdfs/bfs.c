#include"queue.h"

void bfs(ADJNODE * adjlist, int id_source)
{
	VERTEX * current;
	ADJNODE * adjsearch;
	QUEUE * thequeue;
	thequeue = ini_queue();

 	//printf("%d", adjlist[id_source].self->id);	

	en_queue(thequeue, adjlist[id_source].self);
	adjlist[id_source].self->distance = 0;
	adjlist[id_source].self->color = GRAY;
	while (thequeue->head != NULL)
	{
		//printf("queue length = %d\n", thequeue->length); 

		current = del_queue(thequeue);
		current->color = BLACK;
		adjsearch = &adjlist[current->id-1]; //use id number to go back to adjacency list hash table and continue search
		
		//printf("%4d", adjsearch->self->id);

		while (adjsearch != NULL)
		{
			if (adjsearch->self->color == WHITE)
			{
				adjsearch->self->color = GRAY;
				adjsearch->self->distance = current->distance + 1;
				adjsearch->self->pred = current;
				en_queue(thequeue, adjsearch->self);
			}
			
			adjsearch = adjsearch->next;//traverse all in the linked list
		}
	}


}
			
