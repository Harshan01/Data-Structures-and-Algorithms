#include "readRecords.h"


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
