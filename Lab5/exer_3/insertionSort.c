#include "insertionSort.h"


void right_shift(RECORDS record, long start, long end) {
	CREDIT_CARDS credit_cards = record -> credit_cards;	
	for (int i=end; i > start; --i)
		credit_cards[i] = credit_cards[i-1];
}

// INSERTION SORT WITH LOOP
//
// void insertInOrder(RECORDS record, CREDIT_CARD card, int idx) {
// 	CREDIT_CARDS credit_cards = record -> credit_cards;
// 	for (int i = 0; i <= idx; ++i) {
// 		if (card.card_number <= credit_cards[i].card_number) {
// 			right_shift(record, i, idx);
// 			credit_cards[i] = card;
// 			return;
// 		}
// 	}
// }
//
// void insertionSort(RECORDS record) {
// 	for (int i = 0; i < record->size; ++i) {
// 		CREDIT_CARD temp = record->credit_cards[i];
// 		insertInOrder(record, temp, i);
// 	}
// }

void insertInOrder(RECORDS record, int idx) {
	if (idx == record->size) {
		int end_stack_var = 0;
		end_stack = &end_stack_var;
		return;
	}	
	for (long i = 0; i < idx; ++i) {
		if (record->credit_cards[idx].card_number <= record->credit_cards[i].card_number) {
			card = record->credit_cards[idx];
			right_shift(record, i, idx);
			record->credit_cards[i] = card;
			break;
		}
	}
	insertInOrder(record, idx+1);
	return;
}

void insertionSort(RECORDS record) {
	insertInOrder(record, 0);
}
