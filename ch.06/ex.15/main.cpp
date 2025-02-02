#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <set>

struct Gen
{
	std::set<int> stor;
	static const double PI;
	double operator()()
	{
		srand(time(0));
		
		while (true)
		{
			int degrees = rand() % 180;
			if (stor.find(degrees) == stor.end())
			{
				stor.insert(degrees);
				return degrees * PI / 180;
			}
		}
		
	}
};

const double Gen::PI = 3.14;

int main()
{
	std::vector<double> v(10);
	std::generate(v.begin(), v.end(), Gen());
	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;
	std::transform(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "), std::ptr_fun(sin));
	std::cout << std::endl;
}