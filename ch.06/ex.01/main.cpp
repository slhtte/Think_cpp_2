#include <ctime>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

struct My_gen_t
{
	std::clock_t operator()()
	{
		return std::clock();
	}
};

int main()
{
	std::list<std::clock_t> l;
	std::generate_n(std::back_inserter(l), 15, My_gen_t());
	std::unique_copy(l.begin(), l.end(), std::ostream_iterator<std::clock_t>(std::cout, "\n"));
}