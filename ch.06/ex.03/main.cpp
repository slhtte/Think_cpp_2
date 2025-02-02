#include <iostream>
#include <algorithm>


template <class T>
class Sum
{
	T sum = 0;
public:
	T operator()(const T &t)
	{
		sum += t;
		return sum;
	}

	friend std::ostream& operator<<(std::ostream &os, const Sum<T> &s)
	{
		return os << s.sum;
	}
};

int main()
{
	int arr_i[] = { 1, 2, 3, 4, 5 };
//	Sum<int> s;
	Sum<int> s = std::for_each(arr_i, arr_i + 5, Sum<int>());
	std::cout << s << std::endl;
}