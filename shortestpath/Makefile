  


#spsp: spmain.o
#	g++ spmain.o -o spsp

#spmain.o: bellman.c dijkstra.c ini_queue.c queue.h en_queue.c spmain.c 
#	g++ bellman.c dijkstra.c ini_queue.c queue.h en_queue.c spmain.c -o spmain.o

#clean:
#	rm *o spsp

CC=gcc

CFLAGS=-c -Wall -g

all: spsp

spsp: spmain.o bellman.o dijkstra.o ini_queue.o en_queue.o  
	$(CC) spmain.o bellman.o dijkstra.o ini_queue.o en_queue.o -o spsp

spmain.o: queue.h spmain.c
	$(CC) $(CFLAGS) spmain.c

bellman.o: bellman.c queue.h
	$(CC) $(CFLAGS) bellman.c

dijkstra.o: queue.h dijkstra.c
	$(CC) $(CFLAGS) dijkstra.c

ini_queue.o: ini_queue.c queue.h
	$(CC) $(CFLAGS) ini_queue.c

en_queue.o: en_queue.c queue.h
	$(CC) $(CFLAGS) en_queue.c

clean:
	rm -rf *o spsp
