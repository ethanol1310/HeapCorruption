#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *tmp1 = malloc(8);
	strcpy(tmp1, "abcd");
	printf("address tmp1: %p\n", tmp1);
	int c = (int)tmp1;
	printf("Value of c: %x\n", c);
	printf("Freeing valid heap...\n", c);
	free((void *)c);
	int b = 4627;
	printf("Freeing invalid heap...(stack)\n");
	free((void *)&b);
	return 0;
}
