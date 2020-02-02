#include "cycle.h"

int testCyclic(LINKEDLIST ll) {
	if (ll -> count == 0) {
		return 0;
	}
	else if (ll -> count == 1) {
		if (ll -> head -> next == ll -> head)
			return 1;
		else
			return 0;
	}
	else {
		NODE hare, tort;
		hare = ll -> head -> next;
		tort = ll -> head;
		while(1) {
			if (hare -> next == NULL || hare -> next -> next == NULL) {
				return 0;
			}
			else if (hare == tort || hare -> next == tort) {
				return 1;
			}
			hare = hare -> next -> next;
			tort = tort -> next;
		}
		return 0;
	}
}
