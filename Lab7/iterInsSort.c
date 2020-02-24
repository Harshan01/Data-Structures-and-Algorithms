#include "iterQS.h"


void IterInsertionSort(Element Ls[], int sz) {
	for (int i = 1; i < sz; ++i) {
		Element tmp = Ls[i];

		int j = i-1;
		while (j >= 0 && Ls[j].empID > tmp.empID) {
			Ls[j+1] = Ls[j];
			--j;
		}
		Ls[j+1] = tmp;
	}
}
