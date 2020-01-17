/* driver.c */

#include "Stack.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");

	// Declare a pointer to a Stack (head) and allocate memory to it.
	Stack * head = (Stack *) malloc (sizeof(Stack));
	head -> first = NULL;
	head -> count = 0;

	// In a loop read the file and insert elements into the Stack.
	int temp;
	while (fscanf(fileptr, "%d", &temp) == 1)
	{
		// read the next element and store into the temp variable.
		// insert temp into the Stack.
		push(head,temp);
		printf("%d pushed into Stack.\n", temp);
	}
	printf("Pushed elements into Stack from file!\n\n");

	printf("Popped Elements:\n");
	while (head -> count > 0) {
		struct node * ele = pop(head);
		printf("%d popped from Stack.\n", ele -> element);
	}

	printf("\n");
}

