#include <stdio.h>

typedef struct emp_rec {
	char name[11];
	int empID;
} Element;


void readData(FILE * f, Element Ls[], int sz);
