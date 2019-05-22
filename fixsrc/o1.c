#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *a = malloc(100);
	memset(a, 'a', 100);	
	for(int i = 1; i < 100; i++)
	{
		a[i] = 'A'; 
	}

	return 0;
}
