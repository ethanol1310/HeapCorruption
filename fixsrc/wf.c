#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeS(char **ptr)
{
	if(*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
int main(int argc, char **argv)
{
	char *a = malloc(128);
	char *b = malloc(128);
	char *c;
	
	strcpy(a, "string a");
	strcpy(b, "string b");

	printf("address a: %p\n", a);
	printf("string a: %s\n", a);
	printf("address b: %p\n", b);
	printf("string b: %s\n", b);

	printf("freeing a...\n");
	printf("allocate c...\n");
	freeS(&a);
	c = malloc(127);

	printf("address c: %p\n", c);
	printf("string c: %s\n", c);
	printf("put a string here (write after free): string c\n");
	strcpy(c, "string c");	

	printf("address a: %p\n", a);
	printf("string a: %s\n", a);	
	
	return 0;
}
