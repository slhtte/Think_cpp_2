#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

struct Generator
{
	int i;
	Generator(int ii = 1) : i(ii) {}
	int operator()()
	{
		return i++;
	}
};

int main()
{
	std::vector<int> v(6);
	std::generate(v.begin(), v.end(), Generator());
	std::partial_sum(v.begin(), v.end(),
		             std::ostream_iterator<int>(std::cout, " "), std::multiplies<int>());
	std::cout << std::endl;
}