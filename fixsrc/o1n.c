#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	// +1 for NULL
	if((strlen(argv[1]) + 1) > 8)
	{
		printf("Overflow...");
		exit(-1);
	}
	char *a = malloc(8);
	char *b = malloc(8);
	strcpy(a, "123456789");
	strcpy(a, argv[1]);
	return 0;
}
