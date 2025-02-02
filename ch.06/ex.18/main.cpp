#include <iostream>

template <class InputIterator1, class InputIterator2, class BinaryFunc>
BinaryFunc bin_for_each(InputIterator1 first, InputIterator1 last, InputIterator2 res, BinaryFunc f)
{
	while (first != last)
	{
		f(*first++, *res++);
	}

	return f;
}

template <class T1, class T2>
void print (const T1 &t1, const T2 &t2)
{
	std::cout << t1 << " " << t2 << std::endl;
}

int main()
{
	const int SZ = 5;
	int arr[SZ], arr2[SZ];

	for (size_t i = 0; i < SZ; ++i)
	{
		arr[i] = i + 1;
		arr2[i] = (i + 1) * 3 - 1;
	}

	bin_for_each(arr, arr + SZ, arr2, std::ptr_fun(print<int, int>));
}