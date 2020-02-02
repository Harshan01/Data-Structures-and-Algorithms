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
		NODE node1 = ll -> head;
		NODE node2 = node1 -> next;
		NODE node3 = node2 -> next;
		for (; node3 != NULL && node3 != ll -> head; node1=node2, node2=node3, node3=node3->next) {
			node2 -> next = node1;
		}
		if (node3 == NULL)
			return 0;
		else
			return 1;
	}
}
