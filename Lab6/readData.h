#include <stdio.h>

typedef struct student_rec {
	char name[11];
	float cgpa;
} Element;


void readData(FILE * f, Element Ls[], int sz);
