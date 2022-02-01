#include <iostream>
#include <vector>

namespace ft
{
	template <class T>
	class vector_iterator {
	public:
    	typedef T         value_type;
    	typedef T*   pointer;
	private:
		pointer ptr;
	public:
		vector_iterator &operator=(T &ptr)
		{
			return (this->ptr);
		}
		T* operator*(T ptr)
		{
			return (*ptr);
		}
	};
}
//template <class Category,              // iterator::iterator_category
//          class T,					   // iterator::value_type
//          class Distance = ptrdiff_t,  // iterator::difference_type
//          class Pointer = T*,          // iterator::pointer
//          class Reference = T&         // iterator::reference
//          > class iterator;

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T value_type;
			// typedef std::allocate<T>::pointer pointer;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef ft::vector_iterator<T> iterator;
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

			vector (const vector& x); // copy
			~vector()
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
			iterator begin()
			{
				return (this->);
			}
	};
}




void check()
{
	std::vector<int> vec;
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

	ft::vector<int>::iterator ch;
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(1);
	my.push_back(2);

	ch = my.begin();
	std::cout << ch* << std::endl;
	temp = my;


	std::cout << my.size() << "vs" << my.capacity() << std::endl;
	std::cout << my.size() << "vs" << my.capacity() << std::endl;
}

int main(void)
{
	std::vector<int>::iterator it;
	check();
	return (0);
}
