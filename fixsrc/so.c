#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buf[10];
	int len = strlen(argv[1]) < 10 ? strlen(argv[1]) + 1: 10;
	strncpy(buf, argv[1], len);
	//strcpy(buf, argv[1]);
	return 0;
}
