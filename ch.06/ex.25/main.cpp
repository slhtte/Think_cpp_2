#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

struct Solder
{
	std::string name;
	unsigned short born;
	unsigned short duty;
	Solder(const std::string &s = "", const unsigned short b = 1960, const unsigned short d = 1978)
	    : name(s), born(b), duty(d) {}

	bool operator<(const Solder &r)
	{
		if ((born < r.born) || (born == r.born && duty < r.duty))
		{
			return true;
		}
		
		return false;
	}
};

struct Generator
{
	std::string ABC = "abcdefg";
	std::set<std::string> names;
	std::multimap<unsigned short, unsigned short> years;
	Solder operator()()
	{
		while (true)
		{
            std::random_shuffle(ABC.begin(), ABC.end());
            if (names.find(ABC) == names.end())
            {
            	names.insert(ABC);
            	break;
            }
		}

		while (true)
		{
			srand(time(nullptr));
			unsigned short b = 1960 + rand() % 30;
			unsigned short d = b + 18 + rand() % 9;;

			auto it = years.find(b);
			if (it == years.end())
			{
			    years.emplace(b, d);
			    return Solder(ABC, b, d);
			}
			else
			{
				bool found = false;
				auto range = years.equal_range(b);
				for (auto it = range.first; it != range.second; ++it)
				{
					if (it->second == d)
						found = true;
				}

				if (!found)
				{
					years.emplace(b, d);
			        return Solder(ABC, b, d);
				}
			}
		}
	}
};

bool pred(const Solder& s)
{
	return s.duty == 1997 ? false : true;
}

int main()
{
	std::vector<Solder> v(100);

	std::generate(v.begin(), v.end(), Generator());

	std::vector<Solder>::iterator it = std::remove_if(v.begin(), v.end(), pred);

	std::sort(v.begin(), it);
	std::sort(it, v.end());

    for (const Solder &s : v)
    {
    	std::cout << "[" << s.name << "]: " << s.born << " - " << s.duty << std::endl;
    }
}