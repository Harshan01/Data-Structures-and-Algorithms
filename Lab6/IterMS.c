#include "mergeSort.h"

int REC = 0;
int * end_add;

void MergeSortIterative(Element Ls[], int sz) {
	int _2N;
	for (_2N = 2; _2N < sz*2; _2N *= 2) {
		for (int i = 0; i < sz; i += _2N) {
			if (i + _2N/2 >= sz) {
				continue;
			}
			else{
				if (_2N >= sz) {
					int end = 0;
					end_add = &end;
				}
				int sz1 = _2N/2, sz2;
				sz2 = (_2N/2<=(sz-(i+_2N/2)) ? _2N/2 : (sz-(i+_2N/2)));
				Element Ls1[sz1], Ls2[sz2], Ls3[sz1+sz2];
				int l;
				for (l = 0; l < sz1; ++l)
					Ls1[l] = Ls[i+l];
				for (l = 0; l < sz2; ++l)
					Ls2[l] = Ls[i+l+sz1];
				merge(Ls1, sz1, Ls2, sz2, Ls3);
				for (l = 0; l < sz1+sz2; ++l)
					Ls[i+l] = Ls3[l];
			}
		}
	}
}

void MergeSort(Element Ls[], int sz) {
	MergeSortIterative(Ls, sz);
}
