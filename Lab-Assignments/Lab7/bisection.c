#include "bisection.h"


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
