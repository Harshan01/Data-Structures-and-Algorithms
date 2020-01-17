/* driver.c */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");

	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	head -> first = NULL;
	head -> count = 0;

	// In a loop read the file and insert elements into the linkedList.
	int temp;
	while (fscanf(fileptr, "%d", &temp) == 1)
	{
		// read the next element and store into the temp variable.
		// insert temp into the linked list.
		insertFirst(head,temp);
	}

	// close the file pointer
	fclose(fileptr);

	// print the linked list.
	printList(head);

	// delete the first element of the linked list.
	deleteFirst(head);

	// print the linked list again to check if delete was successful.
	printList(head);

	// print the linked list to a new file.
	if (argc > 2) {
		FILE *write_fptr = fopen(argv[2], "w");
		struct node* ptr = deleteFirst(head);
		while(ptr != NULL){
			fprintf(write_fptr, "%d\n", ptr -> element);
			ptr = deleteFirst(head);
		}
		fclose(write_fptr);
	printf("\nSuccessfully printed the linked list in new file!");
	}

	int ele;
	
	// search an element in the linked list.
	printf("\nEnter an element to be searched: ");
	scanf("%d", &ele);
	if(search(head, ele)){
		printf("\nElement '%d' is FOUND!\n", ele);
	}
	else{
		printf("\nElement '%d' is NOT FOUND!\n", ele);
	}

	// delete the first occurrence of an element from the linked list
	printf("\nEnter an element to be deleted: ");
	scanf("%d", &ele);
	delete(head, ele);

	// print the linked list.
	printList(head);

	printf("\n");
}

