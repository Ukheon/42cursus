#include <stdio.h>
#include <stdlib.h>


int		main(void)
{
	float		arr[2][2] = {
		{1, 2},
		{2, 3}
	};

	float det;
	float rot;

	det = 1 / arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	rot = det * (arr[1][1] - arr[0][1]);
	printf("%f\n",det);

}
