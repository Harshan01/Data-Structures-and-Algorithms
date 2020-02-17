#include "merge.h"


void printEle(Element Ls[], int sz) {
	printf("\n");
	for (int i = 0; i < sz; ++i) {
		printf("%f\n", Ls[i].cgpa);
	}
	printf("\n");
}

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]) {
	int i, j, k = 0;
	for (i=0, j=0; i<sz1 && j<sz2;) {
		if (Ls1[i].cgpa <= Ls2[j].cgpa) {
			Ls[k++] = Ls1[i++];
		}
		else {
			Ls[k++] = Ls2[j++];
		}
	}
	for (; i<sz1; ++i)
		Ls[k++] = Ls1[i];
	for (; j<sz2; ++j)
		Ls[k++] = Ls2[j];
}
