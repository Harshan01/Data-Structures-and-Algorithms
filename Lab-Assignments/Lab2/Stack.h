/* Stack.h */

#include "linkedlist.h"

typedef struct linkedList Stack;

void push(Stack * head, int ele);

struct node* pop(Stack * head);
