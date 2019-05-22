#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlenS(char *ptr)
{
	// +1 for NULL
	return strlen(ptr) + 1;
}
int main(int argc, char **argv)
{
	if(strlenS(argv[1]) > 8)
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
