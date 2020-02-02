#include "alloc.h"

typedef int ELEMENT;

struct node {
	ELEMENT ele;
	struct node* next;
};
typedef struct node* NODE;

struct linkedlist {
	NODE head;
	NODE tail;
	int count;
};
typedef struct linkedlist* LINKEDLIST;

LINKEDLIST createList(int N);

LINKEDLIST createCycle(LINKEDLIST ll);

extern int testCyclic(LINKEDLIST ll);
