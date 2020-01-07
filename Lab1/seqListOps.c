/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
	SeqList sl;
	sl.head = nextfreeloc++;
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
	int index = sl.head;
	if (sl.size == 0) {
		st[index].ele = j;
		st[index].next = -1;
		sl.size = 1;
	}
	else if (compare(j, st[index].ele) != GREATER) {
		sl.head = nextfreeloc;
		st[nextfreeloc].ele = j;
		st[nextfreeloc++].next = index;
		++sl.size;
	}
	else {
		while (st[index].next != -1) {
			if (compare(j, st[st[index].next].ele) == GREATER) {
				index = st[index].next;
			}
			else {
				st[nextfreeloc].ele = j;
				st[nextfreeloc].next = st[index].next;
				++sl.size;
				st[index].next = nextfreeloc++;
				break;
			}
		}
		if (st[index].next == -1) {
			st[nextfreeloc].ele = j;
			st[nextfreeloc].next = -1;
			++sl.size;
			st[index].next = nextfreeloc++;
		}
	}
	return sl;

}

void insertelements (JobList list , int size, SeqList s[3])
{

	// Implement this function
	for (int i = 0; i < size; ++i) {
	   s[list[i].pri] = insert(list[i], s[list[i].pri]);
	}

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

	// Implement this function
	int loc = 0;
	for (int i = 2; i >= 0; --i) {
		int index = s[i].head;
		while (st[index].next != -1) {
			ele[loc++] = st[index].ele;
			index = st[index].next;
		}
		ele[loc++] = st[index].ele;
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
