#include <sys/time.h>
#include <math.h>
//#include <string.h>

#include "insertionSort.h"


int main() {
	
	int start_stack_var = 0;
	start_stack = &start_stack_var;

	FILE * out = fopen("logs.txt", "w");
	fprintf(out, "N,READ_TIME_MS,SORT_TIME_MS,STACK_MEM_BYTES\n");

	int T = 11;
	long num_recs[] = {10, 50, 100, 500, 1000, 5000, 10000, 30000, 50000, 80000, 100000, 500000};

	for (int t = 0; t < T; ++t) {

		long N = num_recs[t];

		printf("%ld RECORDS!!!\n", N);
		FILE * f = NULL;

		long file_num;
		if (N >= 100000)
			file_num = 100000;
		else {
			file_num = pow(10, (long)log10(N));
		}

		char file_name[10];
		sprintf(file_name, "%ld", file_num);

		f = fopen(file_name, "r");

		if (f == NULL) {
			printf("File not found!!!\n");
			return -1;
		}
		
		CREDIT_CARDS credit_cards = (CREDIT_CARDS)malloc(sizeof(CREDIT_CARD) * 10);

		RECORDS record = (RECORDS)malloc(sizeof(struct records));
		record -> credit_cards = credit_cards;
		record -> size_alloc = 10;
		record -> size = 0;
		
		struct timeval t1, t2;
		double time_diff;
		
		gettimeofday(&t1, NULL);
		for (long i = 0; i < N; i += file_num) {
			fseek(f, 0, SEEK_SET);
			record = get_records(record, f, file_num);
		}
		gettimeofday(&t2, NULL);

		time_diff = (double)(t2.tv_sec - t1.tv_sec) * 1000;
		time_diff += (double)(t2.tv_usec - t1.tv_usec) / 1000;
		fprintf(out, "%ld,%lf,", N, time_diff);

		gettimeofday(&t1, NULL);		
		insertionSort(record);
		gettimeofday(&t2, NULL);

		time_diff = (double)(t2.tv_sec - t1.tv_sec) * 1000;
		time_diff += (double)(t2.tv_usec - t1.tv_usec) / 1000;
		fprintf(out, "%lf,", time_diff);

		// ASSERT SORTED
		//
		// if (t == 4) {
		// 	printf("\n\n");
		// 	for (int i = 0; i < record->size; ++i)
		// 		printf("%lld\n", record->credit_cards[i].card_number);
		// 	printf("\n\n");
		// }

		long stack_space_used = (long)start_stack - (long)end_stack;

		fprintf(out, "%ld\n", stack_space_used);

		free(record -> credit_cards);
		free(record);
		
		fclose(f);
	}
	fclose(out);

	return 0;
}

