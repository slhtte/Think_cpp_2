#include <vector>
#include <iostream>
#include <list>

template <class T, template <class U, class = std::allocator<U> > class C> 
class Stack
{
	C<T> data;
public:
	Stack() = default;
	void push(T t)
	{
		data.push_back(t);
	}

	const T pop()
	{
		T tmp = data[data.size() - 1];
		data.pop_back();
		return tmp;
	}

	T& operator[](size_t index)
	{
		return data[index];
	}

	size_t size() const
	{
		return data.size();
	}

	typedef typename C<T>::iterator iter;

	iter begin() { return data.begin(); }
	iter end()  { return data.end(); }
};

int main()
{
	Stack<int*, std::list> s;

	for (size_t i = 0; i < 5; ++i)
	{
		s.push(new int(i));
	}

	Stack<int*, std::list>::iter beg = s.begin();
	size_t count = 0;

	while(beg++ != s.end())
	{
		std::cout<< *s[count++] << ' ';
	}

	std::cout << std::endl;

	while (s.size())
	{
        int *p = s.pop();
		std::cout << *p << ' ';
		delete p;
	}

	std::cout << std::endl;
}