#include <string>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

struct Town_t
{
    std::string name;
    unsigned quantity;
    unsigned short high;
    enum weather_e : unsigned short
    {
    	RAINY = 0,
    	SNOWY,
    	CLOUDY,
    	CLEAR
    } weather;

    Town_t(const std::string &n = "abcdefg", const unsigned q = 0, const unsigned short h = 0, const weather_e w = RAINY)
        : name(n), quantity(q), high(h), weather(w) {}

    std::string weather_as_string() const
    {
    	switch (weather)
    	{
    	case RAINY: return "RAINY";
    	case SNOWY : return "SNOWY";
    	case CLOUDY : return "CLOUDY";
    	case CLEAR : return "CLEAR";
    	default: return "RAINY";
    	}
    }
};

struct Town_generator_t
{
	std::string name = "abcdefg";
	std::set<std::string> names;
	std::set<unsigned> quantityes;
	std::set<unsigned short> highes;

	Town_t operator()()
	{
		while (true)
		{
			std::random_shuffle(name.begin(), name.end());

			if (names.find(name) == names.end())
			{
				names.insert(name);
				break;
			}
		}

		unsigned quantity = 0;
		while (true)
		{
			srand(time(nullptr));
			unsigned q = 100 + rand() % 999899;

			if (quantityes.find(q) == quantityes.end())
			{
				quantityes.insert(q);
				quantity = q;
				break;
			}
		}

		unsigned short high = 0;
		while (true)
		{
			srand(time(nullptr));
			unsigned short h = rand() % 7999;

			if (highes.find(h) == highes.end())
			{
				highes.insert(h);
				high = h;
				break;
			}
		}

		return Town_t(name, quantity, high, static_cast<Town_t::weather_e>(quantity % 4));
	}
};

int main()
{
	std::vector<Town_t> towns(50);
	std::generate(towns.begin(), towns.end(), Town_generator_t());

	std::ofstream out("Towns.txt");
	for (const Town_t &t : towns)
	{
		out << t.name << " " << t.quantity << " " << t.high << " " << t.weather_as_string() << std::endl;
	}
}