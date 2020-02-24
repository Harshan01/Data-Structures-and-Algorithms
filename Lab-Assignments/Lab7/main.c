#include <stdlib.h>
#include <string.h>
#include "bisection.h"


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

