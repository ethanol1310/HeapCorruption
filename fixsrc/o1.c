#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int SIZE = 100;
	char *a = malloc(SIZE);
	memset(a, 'a', SIZE);
	// for(int i = 1; i <= 100; i++) -> i = 100 -> o1	
	for(int i = 1; i < SIZE; i++)
	{
		a[i] = 'A'; 
	}

	return 0;
}
