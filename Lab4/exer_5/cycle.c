#include "cycle.h"
#include <math.h>
#include <sys/time.h>

LINKEDLIST createList(int N) {
	LINKEDLIST ll = (LINKEDLIST)myalloc(sizeof(struct linkedlist));
	ll -> head = NULL;
	ll -> tail = NULL;
	ll -> count = 0;
	if (N < 1)
		return ll;
	else {
		NODE node = (NODE)myalloc(sizeof(struct node));
		node -> ele = rand();
		node -> next = NULL;
		ll -> head = node;
		ll -> tail = node;
		ll -> count = 1;
	}
	for (int i = 1; i < N; ++i) {
		NODE node = (NODE)myalloc(sizeof(struct node));
		node -> ele = rand();
		node -> next = NULL;
		ll -> tail -> next = node;
		ll -> tail = node;
		ll -> count++;
	}
	return ll;
}

LINKEDLIST createCycle(LINKEDLIST ll) {
	int coin_toss = rand()%2;
	printf("\nCoin toss is %d", coin_toss);
	if (coin_toss == 1) {
		int r = rand() % (ll -> count);
		NODE tmp = ll -> head;
		for (int i = 0; i < r; ++i) {
			tmp = tmp -> next;
		}
		ll -> tail -> next = tmp;
	}
	return ll;
}

LINKEDLIST makeCircularList(LINKEDLIST ll) {
	if (ll -> count == 1) {
		ll -> head -> next == ll -> head;
	}
	else if (ll -> count > 1) {
		if (ll -> tail -> next == NULL)
			ll -> tail -> next = ll -> head;
		else {
			NODE loopnode = ll -> tail -> next;
			NODE tmp = ll -> head;
			NODE tmp2;
			for (int i = 0; i < ll -> count; ++i) {
				if (tmp != loopnode) {
					ll -> head = tmp -> next;
					myfree(tmp);
					tmp = ll -> head;
				}
				else
					break;
			}
		}
	}
	return ll;
}

int main(int argc, char * argv[]) {

	srand(time(0));
	int N = 100000;
	printf("\n* N = %d\n", N);
	printf("\nBefore creating LL:\nHeap Space used = %d bytes\n", alloc);
	LINKEDLIST ll = createList(N);
	printf("\nAfter creating LL:\nHeap Space used = %d bytes\n", alloc);
	ll = createCycle(ll);
	printf("\nAfter creating Cycle:\nHeap Space used = %d bytes\n", alloc);
	int is_cyclic = testCyclic(ll);
	printf("\nAfter testing Cycle:\nHeap Space used = %d bytes\n", alloc);
	printf("\nThe LinkedList is %s\n", is_cyclic?"Cyclic":"Linear");
	ll = makeCircularList(ll);
	printf("\nAfter making Linked List cyclic:\nHeap Space used = %d bytes\n", alloc);
	return 0;
}

