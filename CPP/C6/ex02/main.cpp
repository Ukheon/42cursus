#include <iostream>

class Base {
public:
	virtual ~Base()
	{
		;
	}
};

class A : public Base {
	~A() { };
};

class B : public Base {
	~B() { };
};

class C : public Base {
	~C() { };
};

Base *generate()
{
	int		i;

	i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	if (p == NULL)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void identify(Base &p)
{
	if (&p == NULL)
		return ;
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
}

int main(void)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();
		identify(ptr);
		std::cout << " = ";
		identify(*ptr);
		delete ptr;
	}
	return (0);
}
