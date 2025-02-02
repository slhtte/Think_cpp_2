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

template<>
int f(int a[], size_t begin, size_t end, int t)
{
	std::cout<< "f<int> :" << std::endl;

	int sum = t;

	while (begin <= end)
	{
		sum += a[begin++];
	}

	return sum;
}


template<>
double f(double a[], size_t begin, size_t end, double t)
{
	std::cout<< "f<double> :" << std::endl;

	double sum = t;

	while (begin <= end)
	{
		sum += a[begin++];
	}

	return sum;
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };

	std::cout << f(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1) << std::endl;

	double arr_d[] = { 1., 2., 3., 4. };

	std::cout << f(arr_d, 0, sizeof(arr_d) / sizeof(arr_d[0]) - 1) << std::endl;
}