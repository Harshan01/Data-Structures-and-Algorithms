#include "que.h"

QUEUE newQ() {
	QUEUE q = (QUEUE)malloc(sizeof(struct queue));
	q -> head = NULL;
	q -> tail = NULL;
	q -> count = 0;
	return q;	
}

bool isEmptyQ(QUEUE q) {
	if (q -> count == 0) {
		return 1;
	}
	return 0;
}

QUEUE delQ(QUEUE q) {
	if (q -> count == 1) {
		q -> head = NULL;
		q -> tail = NULL;
		q -> count = 0;
	}
	else if (q -> head != NULL) {
		q -> head = q -> head -> next;
		q -> count -= 1;
	}
	else {
		printf("\nCannot delete element from queue! Queue already empty!\n");
	}
	return q;
}

ELEMENT front(QUEUE q) {
	if (q -> count > 0) {
		return q -> head -> ele;
	}
	printf("\nThe queue is empty!!!\n");
	return NULL;
}

QUEUE addQ(QUEUE q, ELEMENT e) {
	NODE tmp = (NODE)malloc(sizeof(struct node));
	tmp -> ele = e;
	tmp -> next = NULL;
	if (q -> count == 0) {
		q -> head = tmp;
		q -> tail = tmp;
		q -> count = 1;
	}
	else {
		q -> tail -> next = tmp;
		q -> tail = tmp;
		q -> count += 1;
	}
	return q;
}

int lengthQ(QUEUE q) {
	return q -> count;
}

/*
void main() {
	// test
	QUEUE q = newQ();
	printf("\nIs queue empty? %s\n", isEmptyQ(q)?"YES":"NO");
	q = addQ(q, 1);
	q = addQ(q, 2);
	q = addQ(q, 3);
	//printf("Queue front: %d\n", front(q));
	printf("Length of Queue: %d\n", lengthQ(q));
	q = delQ(q);
	//printf("Queue front: %d\n", front(q));
	printf("Length of Queue: %d\n", lengthQ(q));
}
*/
