#include "Counter.h"
#include <string>
#include <iostream>
#include <cstring>

Counter::Counter(std::ifstream &file, const char format)
{
	this->format = format;
	memset(arr_code, 0, ARR_SIZE);
	std::string tmp;
	while (getline(file, tmp))
	{
		for (size_t i = 0; i < tmp.size(); ++i)
		{
			char c = tmp[i];
			++arr_code[(int)c - OFFSET];
		}
	}
}

void Counter::sort()
{
	for (size_t i = 0; i < ARR_SIZE; ++i)
	{
		if (arr_code[i] == 0)
		{ 
		    continue;
		}

		sorting.emplace_back(Pair((int)i - OFFSET, arr_code[(int)i - OFFSET]));

		if (sorting.size() == 1)
		{
			continue;
		}

		std::vector<Pair>::iterator right = sorting.end() - 1;
		std::vector<Pair>::iterator left = right - 1;

		while (*right < *left)
		{
		    Pair tmp;
		    tmp = *left;
		    *left = *right;
		    *right = tmp;

		    if (left == sorting.begin())
		    {
		    	break;
		    }

		    --left;
		    --right;
		 }
	}
}

bool Counter::Pair::operator<(const Pair &other) const
{
	return (matches == other.matches) ? code < other.code
	                                  : matches < other.matches;
}

void Counter::report()
{
	if (format == 'A' || format == 'D')
	{
		sort();
	}

	std::cout << "Format sequentially, ascending or descending (S//A//D) : " << format << std::endl;

	if (format == 'S')
	{
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			if ((char)i == ' ')
			{
				std::cout << "\tSpace: " << arr_code[i] << std::endl;
				continue;
			}

			std::cout << '\t' << (char)i << ": " << arr_code[i] << std::	endl;
		}
	}
	else if (format == 'A')
	{
		for (int i = sorting.size() - 1; i >= 0; --i)
		{
			if ((char)sorting[i].code == ' ')
			{
				std::cout << "\tSpace: " << sorting[i].matches << std::endl;
				continue;
			}

			std::cout << '\t' << (char)sorting[i].code << ": " << sorting[i].matches << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < sorting.size(); ++i)
		{
			if ((char)sorting[i].code == ' ')
			{
				std::cout << "\tSpace: " << sorting[i].matches << std::endl;
				continue;
			}

			std::cout << '\t' << (char)sorting[i].code << ": " << sorting[i].matches << std::endl;
		}
	}
}