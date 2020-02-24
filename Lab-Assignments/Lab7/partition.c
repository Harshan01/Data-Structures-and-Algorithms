#include "partition.h"


void printEle(Element Ls[], int sz) {
	printf("\n");
	for (int i = 0; i < sz; ++i) {
		printf("%d\n", Ls[i].empID);
	}
	printf("\n");
}

void swap(Element *a, Element *b) {
	Element tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(Element Ls[], int l, int h) {
	// l and h inclusive in Ls
	int pivot = Ls[h].empID;
	int i = l-1;

	for (int j = l; j < h; ++j) {
		if (Ls[j].empID < pivot) {
			++i;
			swap(&Ls[i], &Ls[j]);
		}
	}
	swap(&Ls[i+1], &Ls[h]);
	return i+1;
}
