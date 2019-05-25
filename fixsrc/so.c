#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int SIZE = 10;
	char buf1[SIZE];
	strncpy(buf1, argv[1], sizeof(buf1));

	char *buf2 = malloc(SIZE);
	strncpy(buf2, argv[1], SIZE);
	
	//strcpy(buf, argv[1]);
	return 0;
}
