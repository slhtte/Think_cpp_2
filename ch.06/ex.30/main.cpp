#include "Town.h"
#include <iterator>
#include <functional>

struct great : public std::binary_function<Town_t, Town_t, bool>
{
    bool operator()(const Town_t &left, const Town_t &right) const
    {
        return left.high > right.high;
    }
};

int main()
{
	std::ifstream in("Towns.txt");
	std::vector<Town_t> v;

	Town_t t;
	while (in >> t)
	{
		v.push_back(t);
	}

	std::binary_negate<great> g(great());

	std::sort(v.begin(),
		      v.end(),
		      g);

	std::copy(v.begin(),
		      v.end(),
		      std::ostream_iterator<Town_t>(std::cout, "\n"));
}