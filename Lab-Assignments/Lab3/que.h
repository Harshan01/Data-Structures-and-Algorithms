#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long int TASKID;
typedef int PRIORITY;
struct task {
	TASKID tid;
	PRIORITY p;
};
typedef struct task* TASK;

//typedef int ELEMENT;
typedef TASK ELEMENT;
typedef int bool;

struct node {
	ELEMENT ele;
	struct node* next;
};
typedef struct node* NODE;

struct queue {
	NODE head;
	NODE tail;
	int count;
};
typedef struct queue* QUEUE;

QUEUE newQ();

bool isEmpty(QUEUE q);

QUEUE delQ(QUEUE q);

ELEMENT front(QUEUE q);

QUEUE addQ(QUEUE q, ELEMENT e);

int lengthQ(QUEUE q);
 
