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
	
	return ll;
}

int main(int argc, char * argv[]) {

	srand(time(0));

	int gprof = 0;
	if (argc > 1) {
		gprof = atoi(argv[1]);
	}

	if (!gprof) {
		for (int i = 0; i < 8; ++i) {
			long int N = pow(10, i);
			struct timeval t1, t2;
			double t_d;
			gettimeofday(&t1, NULL);		
			LINKEDLIST ll = createList(N);
			ll = createCycle(ll);
			int is_cyclic = testCyclic(ll);
			gettimeofday(&t2, NULL);
			t_d = (t2.tv_sec - t1.tv_sec) * 1000.0;
			t_d += (t2.tv_usec - t1.tv_usec) / 1000.0;
			printf("\n* N = %ld, Time taken in ms = %lf", N, t_d);
			printf("\nThe LinkedList is %s\n", is_cyclic?"Cyclic":"Linear");
		}
	}
	else {
		for (int i = 0; i < 8; ++i) {
			long int N = pow(10, i);
			LINKEDLIST ll = createList(N);
			ll = createCycle(ll);
			int is_cyclic = testCyclic(ll);
			printf("\n* N = %ld", N);
			printf("\nThe LinkedList is %s\n", is_cyclic?"Cyclic":"Linear");
		}
	}
	return 0;
}

