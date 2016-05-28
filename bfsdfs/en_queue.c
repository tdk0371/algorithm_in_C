#include"queue.h"

void en_queue(QUEUE * line, VERTEX * node)
{
	if (line->head == NULL)
	{
		line->head = node;
		line->rear = node;
		node->next = NULL;
	}
	else
	{
		/*
		VERTEX * nextnode = line->head;
		while (nextnode->next != NULL) nextnode = nextnode->next;
		nextnode->next = node;
		node->next = NULL;
		*/

		line->rear->next = node;
		node->next = NULL;
		line->rear = node;
	}
	line->length++;	
}
