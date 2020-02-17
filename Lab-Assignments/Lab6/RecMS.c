#include "mergeSort.h"

int REC = 1;
int * end_add;

void MergeSortRecursive(Element Ls[], int sz) {	
	if (sz <= 1) {
		int end = 0;
		end_add = &end;
		return;
	}
	int halfIdx = (sz+1)/2;
	Element Ls1[halfIdx], Ls2[sz-halfIdx], Ls3[sz];
	for (int i = 0; i < halfIdx; ++i)
		Ls1[i] = Ls[i];
	for (int i = halfIdx; i < sz; ++i)
		Ls2[i-halfIdx] = Ls[i];
	MergeSortRecursive(Ls1, halfIdx);
	MergeSortRecursive(Ls2, sz-halfIdx);
	merge(Ls1, halfIdx, Ls2, sz-halfIdx, Ls3);
	for (int i = 0; i < sz; ++i) {
		Ls[i] = Ls3[i];
	}
}

void MergeSort(Element Ls[], int sz) {
	MergeSortRecursive(Ls, sz);
}
