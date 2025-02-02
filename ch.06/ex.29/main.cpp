#include "Town.h"
#include <iterator>

int main()
{
	std::ifstream in("Towns.txt");

	std::copy_if(std::istream_iterator<Town_t>(in),
		         std::istream_iterator<Town_t>(),
		         std::ostream_iterator<Town_t>(std::cout, "\n"),
		         std::mem_fun_ref(&Town_t::find_high));
}