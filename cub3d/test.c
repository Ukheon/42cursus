#include <stdio.h>
#include <stdlib.h>


int		main(int argc, char *argv[])
{
	int pad;

	pad = ((4 - (atoi(argv[1])) * 3) % 4) % 4;
	printf("%d\n", pad);
}