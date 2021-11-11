#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::cout << "======== vector ========" << std::endl;
	std::vector<int> vec(10, 100);
	std::vector<int>::iterator iterV;
	iterV = easyfind(vec, 100);
	if (iterV != vec.end())
		std::cout << "found" << std::endl;
	else
		std::cout << "not found" << std::endl;

	std::cout << "======== deque ========" << std::endl;

	std::deque<int> deq;
	std::deque<int>::iterator iterD;
	deq.push_back(10);
	deq.push_back(10);
	iterD = easyfind(deq, 20);
	if (iterD != deq.end())
		std::cout << "found" << std::endl;
	else
		std::cout << "non found" << std::endl;

	std::cout << "======== list ========" << std::endl;

	std::list<int> _list;
	std::list<int>::iterator iterL;
	_list.push_back(20);
	_list.push_back(20);
	iterL = easyfind(_list, 20);
	if (iterL != _list.end())
		std::cout << "found" << std::endl;
	else
		std::cout << "not found" << std::endl;

	std::cout << "======== map ========" << std::endl;
	std::map<int, int> first;
	std::map<int, int>::iterator iterM;
	first[0] = 10;
	first[1] = 20;
	first[2] = 30;
	iterM = easyfind(first, 20);
	if (iterM != first.end())
		std::cout << "found" << std::endl;
	else
		std::cout << "not found" << std::endl;
	return (0);
}
