#include <algorithm>
#include <functional>
#include <iostream>
#include "Generators.h"

int f(int n)
{
	return n % 23;
}



int main()
{
	size_t  SZ = 100;
	int arr[SZ];
	std::generate(arr, arr + SZ, URandGen(100));

	int arr_div[SZ];
	std::transform(arr, arr + SZ, arr_div, std::ptr_fun(f));

	int *start = arr_div;
	int *end = arr_div + SZ;
	bool states[SZ] = { false };

	while (start != end)
	{
		while (states[start - arr_div] && start != end)
		{
			++start;
		}

		int *beg = start + 1;

		while (beg != end)
		{
			beg = std::find(beg, end, *start);
			if (beg != end)
			{
			    std::cout << "[" << *start << "]: " << arr[beg - arr_div] << std::endl;
			    states[beg - arr_div] = true;
			    ++beg;
			}
		}

		++start;
	}
}