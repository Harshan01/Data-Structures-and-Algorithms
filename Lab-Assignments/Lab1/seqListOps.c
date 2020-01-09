/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
	SeqList sl;
	sl.head = nextfreeloc;
	sl.size = 0;
	st[sl.head].next = -1;
	return (sl);
}

void printJob (Job j)
{
	printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}

int inputJobs (JobList list)
{
	int i; int size;

	printf("\n Enter the Number of Jobs :");
	scanf("%d", &size);

	for (i=0;i<size;i++)
	{
		printf ("\nEnter job ID");
		scanf ("%d",&list[i].id);
		printf ("Enter Priority (from 0 - 2)");
		scanf ("%d",&list[i].pri);
		printf ("Execution Time");
		scanf ("%d",&list[i].et);
		printf ("Arrival Time");
		scanf ("%d",&list[i].at);
	}
	return size;
}

int initialize_elements (JobList list) {
	return inputJobs(list);
}

SeqList insert(Job j , SeqList sl)
{

	//Implement this function
	int i;
	for (i = sl.head; i < nextfreeloc; ++i) {
		if (compare(j, st[i].ele) != GREATER) {
			st[nextfreeloc].next = -1;
			st[nextfreeloc-1].next = nextfreeloc;
			for (int j = nextfreeloc-1; j >= i; --j) {
				st[j+1].ele = st[j].ele;
			}
			st[i].ele = j;
			break;
		}
	}
	if (i == nextfreeloc) {
		st[i].ele = j;
		st[i].next = -1;
		if (sl.size != 0)
			st[i-1].next = i;		
	}
	++nextfreeloc;
	++sl.size;
	return sl;

}

void insertelements (JobList list , int size, SeqList s[3])
{

	// Implement this function
	for (int j = 2; j >= 0; --j) {
		s[j].head = nextfreeloc;
		for (int i = 0; i < size; ++i) {
			if (list[i].pri == j) {
				s[j] = insert(list[i], s[j]);
			}
		}
	}
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

	// Implement this function
	for (int i = 0; i < nextfreeloc; ++i) {
		ele[i] = st[i].ele;	
	}

}

void printlist(SeqList sl)
{

	// Implement this function
	if (sl.size == 0) {
		printf("Empty sequence!\n");
	}
	else {	
		printf("Printing SeqList!\n");
		int index = sl.head;
		while (st[index].next != -1) {
			printJob(st[index].ele);
			index = st[index].next;
		}
		printJob(st[index].ele);
	}

}

void printJobList(JobList list, int size)
{

	// Implement this function
	printf("Printing JobList!\n");
	for (int i = 0; i < size; ++i) {
		printJob(list[i]);
	}

}

void sortJobList(JobList list, int size)
{
	SeqList seq[3];
	seq[0] = createlist();
	seq[1] = createlist();
	seq[2] = createlist();
	insertelements (list, size, seq);
	printlist(seq[0]);   
	printlist(seq[1]);
	printlist(seq[2]);
	copy_sorted_ele (seq , list); 
}
