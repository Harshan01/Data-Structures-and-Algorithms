/* File: test.c */

#include <stdio.h>
int main(int argc, char *argv[])
{
	printf("\n%d\n", argc);
	for(int i=1; i<argc; ++i)
		printf("%s ", argv[i]);
}

