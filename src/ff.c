#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Allocating 3 strings.\n");
	char *a = malloc(32);
	char *b = malloc(32);
	char *c = malloc(32);

	printf("a malloc(32): %p\n", a);
	printf("b malloc(32): %p\n", b);
	printf("c malloc(32): %p\n", c);

	printf("Freeing a...\n");
	free(a);


	printf("Freeing b...\n");
	free(b);

	printf("Freeing a again...  ---> Double free\n");
	free(a);

	printf("Allocating 3 strings.\n");
	printf("1st malloc(32): %p\n", malloc(32));
	printf("2nd malloc(32): %p\n", malloc(32));
	printf("3rd malloc(32): %p  ---> Double free\n", malloc(32));
	
	return 0;
}
