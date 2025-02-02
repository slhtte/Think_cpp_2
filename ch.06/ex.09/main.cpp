#include <algorithm>
#include <functional>
#include <iostream>

struct Generator
{
	int val;
	Generator(const int v = 2) : val(v) {}
	int operator()()
	{
		return val++;
	}
};

int main(int argc, char *argv[])
{
	int n = std::atoi(argv[1]);
	size_t SZ = n - 1;
	int *arr = new int[SZ];

	std::generate(arr, arr + SZ, Generator());

    int *beg = arr;
    int *end = arr + SZ;

	while (beg != end)
	{
		beg = std::find_if(beg, end, not1(bind1st(std::modulus<int>(), n)));

		if (beg != end)
		{
			std::cout << *beg++ << std::endl;
		}
	}
}