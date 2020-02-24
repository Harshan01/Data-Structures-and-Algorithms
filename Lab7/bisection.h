#include <sys/time.h>
#include "hybridSort.h"


struct sortTimes {
	long IStime;
	long QStime;
};

struct sortTimes testRun(Element Ls[], int sz);

int estimateCutoff(Element Ls[], int sz);
