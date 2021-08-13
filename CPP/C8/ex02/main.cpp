#include "mutantstack.hpp"
#include <vector>


void subjectTest()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void myTest()
{
	MutantStack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	std::cout << "size : " << s.size() << std::endl;
	std::cout << "now top : " << s.top() << std::endl;
	MutantStack<int>::reverse_iterator rp;
	rp = s.rbegin();
	for (; rp != s.rend(); ++rp)
	{
		std::cout << *rp << std::endl;
	}
}

int main()
{
	subjectTest();
	std::cout << " ========================== " << std::endl;
	myTest();
}

