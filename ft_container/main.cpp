#include <iostream>
#include <vector>

template <class Category,              // iterator::iterator_category
          class T,					   // iterator::value_type
          class Distance = ptrdiff_t,  // iterator::difference_type
          class Pointer = T*,          // iterator::pointer
          class Reference = T&         // iterator::reference
          > class iterator;

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T value_type;
			// typedef std::allocate<T>::pointer pointer;
			typedef Alloc allocator_type;
			typedef size_t size_type;
		private:
			size_type	len;
			size_type	cap;
			value_type	*arr;
			int n;
			allocator_type allocType; // Alloc allocType;

		public:
			explicit vector (const allocator_type& alloc = allocator_type())
			:len(0), cap(0), arr(0), allocType(alloc)
			{
				this->arr = allocType.allocate(0);
			}; // defalut;
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			:len(n), cap(n), arr(0), allocType(alloc) //  n 갯수만큼 0으로 초기화
			{
				this->arr = allocType.allocate(cap);
				for (int i = 0; i < n; i++)
				{
					this->arr[i] = T();
				}
			}

			// template <class InputIterator>
         	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); // range만큼 복사?
			vector (const vector& x); // copy
			~vector()
<<<<<<< HEAD
			{
				allocType.deallocate(this->arr, this->cap);
			}

			vector& operator= (const vector& x)
			{
				this->allocType.deallocate(this->arr, this->cap);
				this->len = x.len;
				this->cap = x.cap;
				this->arr = this->allocType.allocate(x.cap);

				for (size_type i = 0; i < x.len; i++)
					this->arr[i] = x.arr[i];
				return (*this);
			}
			size_type size() const { return (this->len); }
			size_type capacity() const { return (this->cap); }
			void push_back (const value_type& val)
			{
				if (this->len >= this->cap)
				{
					size_type prevSize = this->cap;
					this->cap *= 2;
					if (this->len == 0)
					{
						this->cap = 1;
					}
					value_type *temp = allocType.allocate(this->cap);
					for (size_type i = 0; i < this->len; i++)
						temp[i] = this->arr[i];
					this->allocType.deallocate(this->arr, prevSize);
					this->arr = allocType.allocate(this->cap);
					for (size_type i = 0; i < this->len; i++)
						this->arr[i] = temp[i];
					this->allocType.deallocate(temp, this->cap);
				}
				this->arr[len] = val;
				this->len += 1;
			}

			// void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			T &operator[](unsigned idx)
			{
				return (this->arr[idx]);
			}
	};
}


=======
			{
				allocType.deallocate(this->arr, this->cap);
			}

			vector& operator= (const vector& x)
			{
				this->allocType.deallocate(this->arr, this->cap);
				this->len = x.len;
				this->cap = x.cap;
				this->arr = this->allocType.allocate(x.cap);

				for (size_type i = 0; i < x.len; i++)
					this->arr[i] = x.arr[i];
				return (*this);
			}
			size_type size() const { return (this->len); }
			size_type capacity() const { return (this->cap); }
			void push_back (const value_type& val)
			{
				if (this->len >= this->cap)
				{
					size_type prevSize = this->cap;
					this->cap *= 2;
					if (this->len == 0)
					{
						this->cap = 1;
					}
					value_type *temp = allocType.allocate(this->cap);
					for (size_type i = 0; i < this->len; i++)
						temp[i] = this->arr[i];
					this->allocType.deallocate(this->arr, prevSize);
					this->arr = allocType.allocate(this->cap);
					for (size_type i = 0; i < this->len; i++)
						this->arr[i] = temp[i];
					this->allocType.deallocate(temp, this->cap);
				}
				this->arr[len] = val;
				this->len += 1;
			}

			// void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			T &operator[](unsigned idx)
			{	
				return (this->arr[idx]);
			}
	};
}


>>>>>>> 7d71ff657bc531eba0a60b97c03d0c9d492c722d
namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
	class iterator {
	public:
    	typedef T         value_type;
    	typedef Distance  difference_type;
    	typedef Pointer   pointer;
    	typedef Reference reference;
    	typedef Category  iterator_category;
	private:
		pointer ptr;
	};
}

void check()
{
	std::vector<int> vec;
	// // vec.push_back(1);
	// vec.assign(100, 7);

	// std::cout << vec.size() << "vs" << vec.capacity() << std::endl;

	// // ft::vector<int> my(100);



<<<<<<< HEAD

	// std::allocator<char> alloc;

	// char *num;

	// num = alloc.allocate(5);
=======

	// std::allocator<char> alloc;

	// char *num;
>>>>>>> 7d71ff657bc531eba0a60b97c03d0c9d492c722d

	// num = alloc.allocate(5);

<<<<<<< HEAD
	// for (int i = 0; i < 5; i++)
	// {
	// 	num[i] = 'a';
	// }

	// for (int i = 0;i<5;i++)
	// {
	// 	std::cout << num[i] << std::endl;
	// }

	// alloc.destroy(num);
	// alloc.deallocate(num, 5);

	// for (int i = 0;i<5;i++)
	// 	std::cout << num[i] << std::endl;


	for(int i = 0; i < 10; i++)
		vec.push_back(i);

	std::vector<int>::iterator start;

	start = vec.begin();
	for (; start != vec.end(); ++start)
	{
		if (*start == 5)
			vec.erase(start);
	}

	start = vec.begin();

	for (; start !=vec.end();++start)
		std::cout << *start << std::endl;

	ft::vector<int> my;
	ft::vector<int> temp;
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(2);

=======

	// for (int i = 0; i < 5; i++)
	// {
	// 	num[i] = 'a';
	// }

	// for (int i = 0;i<5;i++)
	// {
	// 	std::cout << num[i] << std::endl;
	// }
	
	// alloc.destroy(num);
	// alloc.deallocate(num, 5);

	// for (int i = 0;i<5;i++)
	// 	std::cout << num[i] << std::endl;


	for(int i = 0; i < 10; i++)
		vec.push_back(i);
	
	std::vector<int>::iterator start;

	start = vec.begin();
	for (; start != vec.end(); ++start)
	{
		if (*start == 5)
			vec.erase(start);
	}

	start = vec.begin();

	for (; start !=vec.end();++start)
		std::cout << *start << std::endl;
	
	ft::vector<int> my;
	ft::vector<int> temp;
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(2);

>>>>>>> 7d71ff657bc531eba0a60b97c03d0c9d492c722d
	temp = my;
	std::cout << my.size() << "vs" << my.capacity() << std::endl;
	std::cout << my.size() << "vs" << my.capacity() << std::endl;
}

int main(void)
{
	std::vector<int>::iterator it;
	check();
	// system("leaks a.out");
	return (0);
}
