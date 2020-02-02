#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int alloc;

void * myalloc(int size);

void myfree(void * addr);
