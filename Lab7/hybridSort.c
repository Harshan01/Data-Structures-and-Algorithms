#include "hybridSort.h"


void HybridSort(Element Ls[], int sz, int S) {
	QuickSort(Ls, sz, S);
	IterInsertionSort(Ls, sz);
}
