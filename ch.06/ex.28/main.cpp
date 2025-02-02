#include "Town.h"
#include <iterator>

int main()
{
	std::ifstream in("Towns.txt");
	/*
	std::vector<Town_t> v;

    Town_t t;
	while (in >> t)
	{
		v.push_back(t);
	}
	in.close();
	*/

	std::istream_iterator<Town_t> it = std::max_element(std::istream_iterator<Town_t>(in),
		                                                std::istream_iterator<Town_t>(),
		                                                less);
	in.close();

	std::ifstream in2("Towns.txt");
	std::istream_iterator<Town_t> it2 = std::min_element(std::istream_iterator<Town_t>(in2),
		                                                 std::istream_iterator<Town_t>(),
		                                                 less);
	std::cout << "Max town: " << *it << std::endl;
	std::cout << "Min town: " << *it2 << std::endl;
}