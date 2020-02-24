#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct emp_rec {
	char name[11];
	int empID;
} Element;

void readData(FILE * f, Element Ls[], int sz) {
	for (int i = 0; i < sz; ++i) {
		fscanf(f, "%s %d", Ls[i].name, &Ls[i].empID);
		//fgetc(f);
	}
}

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

void HybridSort(Element Ls[], int sz, int S) {
	QuickSort(Ls, sz, S);
	IterInsertionSort(Ls, sz);
}

struct sortTimes {
	long IStime;
	long QStime;
};

struct sortTimes testRun(Element Ls[], int sz) {
	Element Ls1[sz], Ls2[sz];
	for (int i = 0; i < sz; ++i) {
		Ls1[i] = Ls[i];
		Ls2[i] = Ls[i];
	}

	struct timeval t1, t2;
	struct sortTimes tt;

	gettimeofday(&t1, NULL);
	IterInsertionSort(Ls1, sz);
	gettimeofday(&t2, NULL);
	tt.IStime = (t2.tv_sec - t1.tv_sec)*1000000;
	tt.IStime += (t2.tv_usec - t1.tv_usec);

	gettimeofday(&t1, NULL);
	QuickSort(Ls2, sz, 1);
	gettimeofday(&t2, NULL);
	tt.QStime = (t2.tv_sec - t1.tv_sec)*1000000;
	tt.QStime += (t2.tv_usec - t1.tv_usec);

	return tt;
}

int estimateCutoff(Element Ls[], int sz) {
	int min=1, max=sz;
	struct sortTimes tt1 = testRun(Ls, min);
	if (tt1.IStime > tt1.QStime)
		return -1;
	struct sortTimes tt2 = testRun(Ls, max);
	if (tt2.IStime < tt2.QStime)
		return -1;

	int mid, _min, _max;
	_min = 1;
	_max = sz;
	do {
		mid = (min + max)/2;
		struct sortTimes tt = testRun(Ls, mid);
		if (tt.IStime < tt.QStime) {
			_min = min;
			min = mid;
		}
		else {
			_max = max;
			max = mid;
		}
	} while((_max != max || _min != min) && (min != max));
	return mid;
}

int main(int argc, char *argv[]) {
	int sz = atoi(argv[1]);
	
	FILE * f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("Cannot open File!\n");
		return -1;
	}

	FILE * out = fopen(argv[2], "w");

	Element Ls[sz];
	readData(f, Ls, sz);

	int cutoff = estimateCutoff(Ls, sz);

	struct timeval t1, t2;
	double time_diff;

	gettimeofday(&t1, NULL);
	HybridSort(Ls, sz, cutoff);
	gettimeofday(&t2, NULL);

	time_diff = (t2.tv_sec - t1.tv_sec) * 1000;
	time_diff += (double)(t2.tv_usec - t1.tv_usec) / 1000;

	printf("N: %d\nCutoff: %d\nTime taken: %lf ms\n\n", sz, cutoff, time_diff);

	for (int i = 0; i < sz; ++i) {
		fprintf(out, "%s %d\n", Ls[i].name, Ls[i].empID);
	}
	// printEle(Ls, N);

	fclose(f);
	fclose(out);
	
	return 0;
}

