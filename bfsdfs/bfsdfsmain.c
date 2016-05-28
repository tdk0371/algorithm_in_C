#include"queue.h"
#include<stdio.h>

extern void bfs(ADJNODE * adjlist, int id_source);
extern void dfs(ADJNODE * adjlist, int id_source, ADJNODE * adjlisthead);

int time;  //global time variable for dfs

int main()
{

int i;

/*******************adjacency list ini*******************/
VERTEX vertexs[12];
for (i=0;i<12;i++)
{
	vertexs[i].id = i+1;
	vertexs[i].next = NULL;
	vertexs[i].pred = NULL;
	vertexs[i].distance = 9999;
	vertexs[i].discover = 0;
	vertexs[i].finish = 0;
	vertexs[i].color = WHITE;
}

ADJNODE adjlist[12];
for (i=0;i<12;i++)
{
	adjlist[i].self = &vertexs[i];
	adjlist[i].next = NULL;
}

ADJNODE adjlist01;
adjlist[0].next = &adjlist01;
adjlist01.self = &vertexs[1];
adjlist01.next = NULL;

ADJNODE adjlist11, adjlist12, adjlist13;
adjlist[1].next = &adjlist11;
adjlist11.self = &vertexs[2];
adjlist11.next = &adjlist12;
adjlist12.self = &vertexs[3];
adjlist12.next = &adjlist13;
adjlist13.self = &vertexs[0];
adjlist13.next = NULL;

ADJNODE adjlist21, adjlist22;
adjlist[2].next = &adjlist21;
adjlist21.self = &vertexs[1];
adjlist21.next = &adjlist22;
adjlist22.self = &vertexs[3];
adjlist22.next = NULL;

ADJNODE adjlist31, adjlist32, adjlist33, adjlist34;
adjlist[3].next = &adjlist31;
adjlist31.self = &vertexs[1];
adjlist31.next = &adjlist32;
adjlist32.self = &vertexs[2];
adjlist32.next = &adjlist33;
adjlist33.self = &vertexs[5];
adjlist33.next = &adjlist34;
adjlist34.self = &vertexs[4];
adjlist34.next = NULL;

ADJNODE adjlist41, adjlist42, adjlist43;
adjlist[4].next = &adjlist41;
adjlist41.self = &vertexs[3];
adjlist41.next = &adjlist42;
adjlist42.self = &vertexs[5];
adjlist42.next = &adjlist43;
adjlist43.self = &vertexs[6];
adjlist43.next = NULL;

ADJNODE adjlist51, adjlist52, adjlist53;
adjlist[5].next = &adjlist51;
adjlist51.self = &vertexs[3];
adjlist51.next = &adjlist52;
adjlist52.self = &vertexs[4];
adjlist52.next = &adjlist53;
adjlist53.self = &vertexs[6];
adjlist53.next = NULL;

ADJNODE adjlist61, adjlist62, adjlist63, adjlist64;
adjlist[6].next = &adjlist61;
adjlist61.self = &vertexs[5];
adjlist61.next = &adjlist62;
adjlist62.self = &vertexs[4];
adjlist62.next = &adjlist63;
adjlist63.self = &vertexs[7];
adjlist63.next = &adjlist64;
adjlist64.self = &vertexs[9];
adjlist64.next = NULL;

ADJNODE adjlist71, adjlist72;
adjlist[7].next = &adjlist71;
adjlist71.self = &vertexs[6];
adjlist71.next = &adjlist72;
adjlist72.self = &vertexs[8];
adjlist72.next = NULL;

ADJNODE adjlist81, adjlist82, adjlist83;
adjlist[8].next = &adjlist81;
adjlist81.self = &vertexs[7];
adjlist81.next = &adjlist82;
adjlist82.self = &vertexs[9];
adjlist82.next = &adjlist83;
adjlist83.self = &vertexs[10];
adjlist83.next = NULL;

ADJNODE adjlist91, adjlist92;
adjlist[9].next = &adjlist91;
adjlist91.self = &vertexs[6];
adjlist91.next = &adjlist92;
adjlist92.self = &vertexs[8];
adjlist92.next = NULL;

ADJNODE adjlist101, adjlist102;
adjlist[10].next = &adjlist101;
adjlist101.self = &vertexs[8];
adjlist101.next = &adjlist102;
adjlist102.self = &vertexs[11];
adjlist102.next = NULL;

ADJNODE adjlist111;
adjlist[11].next = &adjlist111;
adjlist111.self = &vertexs[10];
adjlist111.next = NULL;

/*****************end of adjacency list ini************************/


//bfs(adjlist, 11);

dfs(adjlist, 0, adjlist);

for (i=0;i<12;i++)
{
	printf("in vertex %3d the distance is %3d\n", i+1, vertexs[i].distance);
}

for (i=0;i<12;i++)
{
	printf("in vertex %3d the discover is %3d, finish is %3d\n", i+1, vertexs[i].discover, vertexs[i].finish);
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
