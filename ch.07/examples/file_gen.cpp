#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>

struct Generator_t
{
	unsigned i = 0;
	unsigned operator()()
	{
		return i++;
	}
};

int main()
{
	std::ofstream out("test.out");
	std::generate_n(std::ostream_iterator<unsigned>(out, "\n"), 1000000, Generator_t());
}