#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>

struct Gen
{
	unsigned i = 1;
	unsigned operator()(const unsigned t)
	{
		return i++;
	}
};

int main()
{
	std::vector<unsigned> v(10000000);
	std::transform(v.begin(), v.end(), v.begin(), Gen());

	auto start = std::chrono::high_resolution_clock::now();
	auto i = std::find(v.begin(), v.end(), 1000000);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end - start;
	std::cout << diff.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
	auto n = std::binary_search(v.begin(), v.end(), 10000000);
	end = std::chrono::high_resolution_clock::now();

	diff = end - start;
	std::cout << std::fixed << diff.count() << std::endl;
}