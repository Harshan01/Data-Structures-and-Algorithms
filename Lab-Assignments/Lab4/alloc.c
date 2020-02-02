//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include "alloc.h"

int alloc;

void * myalloc(int size)
{
	alloc += size;	
	return malloc(size);
}

void myfree(void * addr)
{
	alloc -= sizeof(*addr);
	free(addr);
}

/*
int main()
{
	srand(time(0));
	int M;
	alloc = 0;
	for (int i = 0; i < 10; ++i) {
		M = 10000 + (rand() % 15001);
		void * block = myalloc(M);
		printf("%d\t%d\t%u\t%u\n", M, alloc, block, (block+M-1));
		myfree(block);
		if (!block)
			break;
	}
	return 0;
}
*/
