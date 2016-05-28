#include<stdio.h>
#include<stdlib.h>



int * mergesort(const int *start, const int *end); //merge sort 

void merge(int arr[], int l, int m, int r);
void mergeSort2(int arr[], int l, int r);


void insertion(int arr[], int len);  //insertion sort




void heapify(int arr[], int i, int n);  //heap sort

void buildmaxheap(int arr[], int n);  //heap sort

void heapsort(int arr[], int size); //heap sort
