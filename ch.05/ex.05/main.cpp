#include <iostream>

template <class T>
T f(T a[], size_t begin, size_t end, T t = T())
{
	T sum = t;

	while (begin <= end)
	{
		sum += a[begin++];
	}

	return sum;
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };

	std::cout << f(arr, 2, sizeof(arr) / sizeof(arr[0]) - 1) << std::endl;
}