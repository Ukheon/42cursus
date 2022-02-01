#include <iostream>
#include <ctime>

int main(void)
{
	int **arr = new int*[1000];

	for (int i = 0; i < 1000; i++)
	{
		arr[i] = new int[1000];
	}

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			arr[i][j] = j;
		}
	}
	long long int res;

	res = 0;
	//clock_t start = clock();
	//for (int i = 0; i < 1000; i++)
	//{
	//	for (int j = 0; j < 1000; j++)
	//	{
	//		res = res + arr[j][i];
	//	}
	//}
	//clock_t end = clock();

	//std::cout << "걸린시간 : " << difftime(end, start) / 1000.0 << "초" << res <<  std::endl;


	clock_t start = clock();
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			res = res + arr[i][j];
		}
	}
	clock_t end = clock();

	std::cout << "걸린시간 : " << difftime(end, start) / 1000.0 << "초" << res << std::endl;

	return (0);
}
