#include <sys/time.h>
#include <string.h>
#include "mergeSort.h"

extern int REC;
extern int * end_add;
int * start_add;

int main() {
	// EDIT N for inputs of multiple sizes (MAX: 10240)
	int N = 10240;
	start_add = &N;

	char filename[10];
	sprintf(filename, "%d", N);
	if (N != 1024 && N != 10240) {
		sprintf(filename, "10240");
	}

	strcat(filename, ".txt");
	FILE * f = fopen(filename, "r");
	if (f == NULL) {
		printf("Cannot open File!\n");
		return -1;
	}
	FILE * out = fopen("logs.txt", "a");
	if (out == NULL) {
		printf("Error writing to file!\n");
		return -1;
	}

	fprintf(out, "%s\n", REC?"RECURSIVE_MS":"ITERATIVE_MS");
	fprintf(out, "N, TIME_MS, SPACE_BYTES\n");

	Element Ls[N];
	readData(f, Ls, N);
	
	struct timeval t1, t2;
	double time_diff;

	gettimeofday(&t1, NULL);
	MergeSort(Ls, N);
	gettimeofday(&t2, NULL);

	time_diff = (t2.tv_sec - t1.tv_sec) * 1000;
	time_diff += (double)(t2.tv_usec - t1.tv_usec) / 1000;

	long space_used = (long)start_add - (long)end_add;
	fprintf(out, "%d, %lf, %ld\n\n", N, time_diff, space_used);

	// printEle(Ls, N);
	
	return 0;
}

