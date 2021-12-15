#include <iostream>
#include <vector>
template <typename T>
class ft_vector {
	private:
	public:
		T *arr;
		size_t size;
		size_t cap;
		ft_vector()
		{
			this->size = 0;
			this->cap = 1;
			this->arr = new T[this->cap];
		}
		~ft_vector()
		{
			delete [] arr;
		}
		void push_back(const T &res)
		{
			if (this->size >= this->cap)
				this->cap = this->cap * 2;
			T *temp = new T[this->cap];
			for (size_t i = 0; i < this->size; i++)
				temp[i] = this->arr[i];
			temp[this->size] = res;
			delete [] this->arr;
			this->arr = new T[this->cap];
			for (size_t i = 0; i < this->size; i++)
				this->arr[i] = temp[i];
			this->arr[this->size] = temp[this->size];
			this->size = this->size + 1;
		}
		void print()
		{
			for (int i = 0; i < this->size; i++)
			{
				std::cout << this->arr[i] << "kk" << std::endl;
			}
		}
		size_t capacity() { return (this->cap); }

};

class test {
	public:
		int *i;
		test() {
			std::cout << "construct" << std::endl;
		}
		test(int num)
		{
			i = new int(num);
		}
		~test()
		{
			delete this->i;
			std::cout << "destruct" << std::endl;
		}
};

void check()
{
	// std::allocator<int> alloc;
	// test *c = new test(5);
	// test *cd = new test[10];




	// int *a = alloc.allocate(100);
	// for (int i = 0; i < 100; i++)
	// {
	// 	a[i] = i;
	// 	std::cout << a[i] << "숫자" << std::endl;
	// }
	// delete [] a;

	// int *b = new int();
	// delete b;
	// delete c;

	// delete [] cd;

	test *c = new test[2];
	c[0].i = new int(10);
	c[1].i = new int(20);
	
	// char **split = new char*[5];
	// split[0] = new char[10];
	// split[0][0] = '1';

	// delete [] split;
	// delete *split;
	// delete split;

}

int main(void)
{
	// ft_vector<int> myvec;
	// std::vector<int> vec;
	// for (int i = 0; i < 16; i++)
	// 	myvec.push_back(i);
	// for (int i = 0; i < 16; i++)
	// 	vec.push_back(i);
	check();
	// // for (int i = 0 ; i < 130; i++)
	// // 	test.push_back(1);
	// // std::cout << test.capacity() << std::endl;
	// // std::cout << myvec.arr[0] << std::endl;
	// // std::cout << myvec.arr[1] << "size :" << myvec.size <<  std::endl;
	// myvec.print();
	// std::cout << myvec.capacity() << std::endl;
	// std::cout << vec.capacity() << std::endl;
	system("leaks a.out");
	return (0);
}