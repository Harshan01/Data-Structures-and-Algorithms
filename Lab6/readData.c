#include "readData.h"


void readData(FILE * f, Element Ls[], int sz) {
	for (int i = 0; i < sz; ++i) {
		fscanf(f, "%[^,],%f\n", Ls[i].name, &Ls[i].cgpa);
		//fgetc(f);
	}
}
