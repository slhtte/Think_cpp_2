#include "Town.h"
#include <iterator>

struct Town_transformator_t
{
    Town_t operator()(const Town_t &town)
    {
	    Town_t res = town;
	    res.quantity = town.quantity + town.quantity / 10;
	    return res;
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
	in.close();

	std::ofstream out("Towns.txt");
	std::transform(v.begin(),
		           v.end(),
		           std::ostream_iterator<Town_t>(out, "\n"),
		           Town_transformator_t());
}