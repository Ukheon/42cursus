#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <list>

class test {
public:
	int idx;
	test(int n)
	{
		this->n = n;
	}
	int n;
	std::vector<int> arr;
};

int sum(int a, int b)
{
	return (a + b);
}


int main(void){
	int (*f)(int, int);
	f = sum;
	std::cout << f(10 ,20) << std::endl;
	return (0);
}
