#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	printf("\n");
	if (argc < 3) {
		printf("Provide two files!\n");
		exit(1);
	}
	FILE *read_file = fopen(argv[1], "r");
	FILE *write_file = fopen(argv[2], "w");
	if (read_file == NULL || write_file == NULL) {
		printf("File not found!\n");
		exit(1);
	}
	char str[100];
	while(fgets(str, 100, read_file) != NULL)
	{
		fprintf(write_file, "%s", str);
	}
	printf("\nFile contents copied!\n");
}	

