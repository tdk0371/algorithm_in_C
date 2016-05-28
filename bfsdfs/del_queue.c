#include"queue.h"

VERTEX * del_queue(QUEUE * line)
{
	if (line->head == NULL) return NULL;
	else
	{
		VERTEX * popout;
		popout = line->head;
		line->head = line->head->next;
		line->length--;
		return popout;
	}


}
