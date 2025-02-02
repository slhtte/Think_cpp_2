#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

struct Gen
{
	int operator()()
	{
		return rand();
	}
};

int main()
{
	const size_t SZ = 1000000;
	int arr1[SZ], arr2[SZ];

	srand(time(nullptr));
	std::generate(arr1, arr1 + SZ, Gen());

	srand(time(nullptr));
	std::generate(arr2, arr2 + SZ, Gen());

	std::cout << std::equal(arr1, arr1 + SZ, arr2) << std::endl;
}