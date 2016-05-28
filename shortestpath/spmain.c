#include"queue.h"
#include<stdio.h>

extern void bellman(ADJNODE * adjlist, int source, int total);
extern void dijkstra(ADJNODE * adjlist, int source, int total);


int time;  //global time variable for dfs

int main()
{

int i;

/*******************adjacency list ini*******************/
VERTEX vertexs[7];
for (i=0;i<7;i++)
{
	vertexs[i].id = i+1;
	vertexs[i].next = NULL;
	vertexs[i].pred = NULL;
	vertexs[i].distance = 9999;
	vertexs[i].discover = 0;
	vertexs[i].finish = 0;
	vertexs[i].color = WHITE;
}

ADJNODE adjlist[7];
for (i=0;i<7;i++)
{
	adjlist[i].self = &vertexs[i];
	adjlist[i].next = NULL;
	adjlist[i].weight = 0;
}

ADJNODE adjlist01, adjlist02;
adjlist[0].next = &adjlist01;
adjlist01.self = &vertexs[1];
adjlist01.weight = 1;
adjlist01.next = &adjlist02;
adjlist02.self = &vertexs[2];
adjlist02.weight = 5;
adjlist02.next = NULL;

ADJNODE adjlist11, adjlist12;
adjlist[1].next = &adjlist11;
adjlist11.self = &vertexs[2];
adjlist11.weight = 3;
adjlist11.next = &adjlist12;
adjlist12.self = &vertexs[3];
adjlist12.weight = 2;
adjlist12.next = NULL;

ADJNODE adjlist21, adjlist22;
adjlist[2].next = &adjlist21;
adjlist21.self = &vertexs[3];
adjlist21.weight = 7;
adjlist21.next = &adjlist22;
adjlist22.self = &vertexs[6];
adjlist22.weight = 10;
adjlist22.next = NULL;

ADJNODE adjlist31, adjlist32, adjlist33;
adjlist[3].next = &adjlist31;
adjlist31.self = &vertexs[4];
adjlist31.weight = 2;
adjlist31.next = &adjlist32;
adjlist32.self = &vertexs[5];
adjlist32.weight = 1;
adjlist32.next = &adjlist33;
adjlist33.self = &vertexs[6];
adjlist33.weight = 15;
adjlist33.next = NULL;

ADJNODE adjlist41;
adjlist[4].next = &adjlist41;
adjlist41.self = &vertexs[5];
adjlist41.weight = 3;
adjlist41.next = NULL;

ADJNODE adjlist51, adjlist52;
adjlist[5].next = &adjlist51;
adjlist51.self = &vertexs[6];
adjlist51.weight = 4;
adjlist51.next = NULL;

ADJNODE adjlist61;
adjlist[6].next = &adjlist61;
adjlist61.self = &vertexs[0];
adjlist61.weight = 11;
adjlist61.next = NULL;  //make a positive loop


/*****************end of adjacency list ini************************/

bellman(adjlist, 0, 7);
dijkstra(adjlist, 0, 7);


for (i=0;i<7;i++)
{
	printf("in vertex %3d the distance is %3d\n", i+1, vertexs[i].distance);
}


/***********queue functioning test***************************
QUEUE * thequeue;

VERTEX data1 = {1, NULL, NULL, NULL, 0, BLACK};
VERTEX data2 = {2, NULL, NULL, NULL, 1, WHITE};
VERTEX data3 = {3, NULL, NULL, NULL, 2, GRAY};
VERTEX data4 = {4, NULL, NULL, NULL, 3, GRAY};
VERTEX * del;

thequeue = ini_queue();

en_queue(thequeue, &data1);
en_queue(thequeue, &data2);
en_queue(thequeue, &data3);
en_queue(thequeue, &data4);


printf("head = %d\n", thequeue->head->id);
printf("rear = %d\n", thequeue->rear->id);

del = del_queue(thequeue);


printf("head = %d\n", thequeue->head->id);
printf("deleted = %d\n", del->id);

del = del_queue(thequeue);
printf("deleted = %d\n", del->id);
printf("head = %d\n", thequeue->head->id);
*********************************************************/

return 0;
}
