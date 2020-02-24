#include "iterQS.h"


void IterQuickSort(Element Ls[], int l, int h, int S) {
	// l and h are inclusive
	int stack[h-l+1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while (top >= 0) {
		h = stack[top--];
		l = stack[top--];

		int p = partition(Ls, l, h);

		if (p - l > S) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (h - p > S) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

void QuickSort(Element Ls[], int sz, int S) {
	IterQuickSort(Ls, 0, sz-1, S);
}
