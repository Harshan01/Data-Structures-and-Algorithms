/* Stack.c */

#include "Stack.h"

void push(Stack * head, int ele) {
	insertFirst(head, ele);
}

struct node* pop(Stack * head) {
	return deleteFirst(head);
}
