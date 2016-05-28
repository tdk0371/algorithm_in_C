#include"queue.h"

QUEUE * ini_queue()
{
	QUEUE * queue = (QUEUE *)malloc(sizeof(QUEUE));
	queue->head = NULL;
	queue->rear = NULL;
	queue->length = 0;
	return queue;

}
