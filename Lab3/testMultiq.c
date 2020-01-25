#include "multiq.h"
#include <sys/time.h>

MULTIQ loadData(FILE * f) {
	MULTIQ mq = createMQ(10);
	TASKID tid;
	PRIORITY p;
	while(fscanf(f, "%ld,%d\n", &tid, &p) == 2) {
		TASK t = (TASK)malloc(sizeof(struct task));
		t -> tid = tid;
		t -> p = p;
		addMQ(mq, t);
	}
	return mq;
}

MULTIQ testDel(MULTIQ mq, int num) {
	for(int i = 0; i < num; ++i) {
		delNextMQ(mq);
	}
	return mq;
}

int main(int argc, char * argv[]) {

	int numDelOps = 9;

	int gprof = 0;
	if (argc < 2) {
		printf("\nPlease enter Input test file!!!\n");
		return -1;
	}
	if (argc > 2) {
		int tmp = atoi(argv[2]);
		if (tmp > 0)
			numDelOps = tmp;
		if (argc > 3 && !strcmp(argv[3], "1")) {
			gprof = 1;
		}
	}	

	printf("%s", gprof?"Using Gprof!\n":"Not using Gprof!\n\n");

	FILE * inp = fopen(argv[1], "r");

	if (!gprof) {
		struct timeval t1, t2, t3, t4;
		double t_d;

		gettimeofday(&t1, NULL);
		MULTIQ mq = loadData(inp);
		gettimeofday(&t2, NULL);
		t_d = (t2.tv_sec - t1.tv_sec) * 1000.0;
		t_d += (t2.tv_usec - t1.tv_usec) / 1000.0;
		printf("Time for loadData: %lf ms\n", t_d);

		gettimeofday(&t3, NULL);
		testDel(mq, numDelOps);
		gettimeofday(&t4, NULL);
		t_d = (t4.tv_sec - t3.tv_sec) * 1000.0;
		t_d += (t4.tv_usec - t3.tv_usec) / 1000.0;
		printf("Time for testDel for %d elements: %lf ms\n", numDelOps, t_d);
		printf("Average Cost: %lf ms/operation\n", t_d/numDelOps);
	}
	else {
		MULTIQ mq = loadData(inp);

		testDel(mq, numDelOps);
	}

	fclose(inp);

	printf("\nAll tasks executed!!!\n"); 	

	return 0;
}
