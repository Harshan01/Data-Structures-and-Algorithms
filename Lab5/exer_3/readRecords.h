#include <stdio.h>
#include <stdlib.h>

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


int * start_stack;
int * end_stack;
CREDIT_CARD card;


RECORDS get_records(RECORDS record, FILE * f, long N);
