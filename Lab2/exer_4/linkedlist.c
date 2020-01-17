/* linkedlist.c */

#include "linkedlist.h"

//insert first item
void insertFirst(struct linkedList * head, int ele){
	//create a node
	struct node *link = (struct node*) malloc (sizeof(struct node)); 
	/* by this you are creating a node whose address is being stored in the link pointer. */
	link->element = ele;
	//point it to old first node
	link->next = head->first;
	//point first to new first node
	head -> first = link;
	head -> count ++;
}

//delete first item
struct node* deleteFirst(struct linkedList * head){
	struct node *temp = NULL;
	if (head -> count > 0){
		temp = head -> first;	
		head -> first = temp -> next;
		head -> count --;
	}
	return temp;
}

//display the list
void printList(struct linkedList * head){
	struct node *ptr = head -> first;
	printf("\n[ ");
	//start from the beginning
	while(ptr != NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]");
}

int search(struct linkedList * head, int ele){
	struct node *ptr = head -> first;
	while(ptr != NULL){
		if(ptr -> element == ele)
			return 1;
		ptr = ptr -> next;
	}
	return 0;
}

struct node* delete (struct linkedList * head, int ele){
	struct node *ptr = head -> first;
	struct node *tmp = NULL;
	if (ptr -> element == ele)
		deleteFirst(head);
	while(ptr != NULL && ptr->next != NULL){
		if (ptr -> next -> element == ele){
			tmp = ptr -> next;
			ptr -> next = tmp -> next;
			head -> count --;
			return tmp;
		}
		ptr = ptr -> next;
	}
	printf("\nElement %d not found!\n", ele);
	return tmp;
}

