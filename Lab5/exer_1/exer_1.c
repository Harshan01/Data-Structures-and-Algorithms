#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
//#include <string.h>


typedef struct credit_card {
	long long card_number;
	char bank_code[5];
	char expiry_date[7];
	char first_name[30];
	char last_name[30];
} CREDIT_CARD;
typedef CREDIT_CARD* CREDIT_CARDS;

struct records {
	CREDIT_CARDS credit_cards;
	long size_alloc;
	long size;
};
typedef struct records* RECORDS;


RECORDS get_records(RECORDS record, FILE * f, long N) {
	
	CREDIT_CARDS credit_cards = record -> credit_cards;
	
	char line[100], temp[30];
	long temp_size = record->size;
	for (long i = temp_size; i < N+temp_size; ++i) {
		if (i + 1 > record->size_alloc) {
			record->size_alloc *= 2;
			credit_cards = (CREDIT_CARDS)realloc(credit_cards, sizeof(CREDIT_CARD)*record->size_alloc);
		}

		//
		fscanf(f, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"", 
			&credit_cards[i].card_number,
			credit_cards[i].bank_code,
			credit_cards[i].expiry_date,
			credit_cards[i].first_name,
			credit_cards[i].last_name
		);
		fgetc(f);
		//

		/*
		//
		fscanf(f, "\"%[^\"\n]", line);

		strncpy(temp ,line, 16);
		credit_cards[i].card_number = atoll(temp);

		strncpy(credit_cards[i].bank_code, line+17, 5);
		strncpy(credit_cards[i].expiry_date, line+23, 7);

		int k = 31;
		for (int j = 0; line[k] != ','; ++j, ++k) {
			credit_cards[i].first_name[j] = line[k];
		}
		++k;
		for (int j = 0; line[k] != '\n'; ++j, ++k) {
			credit_cards[i].last_name[j] = line[k];
		}
		fgetc(f);
		fgetc(f);
		//
		*/

		++record -> size;
	}

	record -> credit_cards = credit_cards;
	return record;
}


int main() {
	
	FILE * out = fopen("logs.txt", "w");
	fprintf(out, "N,READ_TIME_MS\n");

	int T = 7;
	long num_recs[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};

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
			// printf("%ld credit cards recorded! %ld credit cards space allocated!\n", record -> size, record -> size_alloc);
		}
		gettimeofday(&t2, NULL);

		time_diff = (double)(t2.tv_sec - t1.tv_sec) * 1000;
		time_diff += (double)(t2.tv_usec - t1.tv_usec) / 1000;
		fprintf(out, "%ld,%lf\n", N, time_diff);

		free(record -> credit_cards);
		free(record);
		
		fclose(f);
	}
	fclose(out);

	return 0;
}

