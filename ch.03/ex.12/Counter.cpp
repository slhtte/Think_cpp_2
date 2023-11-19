#include "Counter.h"
#include <string>

Counter::Counter(const std::ifstream &file, const char format)
{
	this->format = format;
	sorting = std::vector<size_t>(ARR_SIZE);
	std::memset(arr_code, 0, ARR_SIZE);
	std::memset(arr_char, 0, ARR_SIZE);
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

void Cunter::sort(char c)
{
	for (size_t i = 0; i < ARR_SIZE; ++i)
	{
		
	}
}

void Counter::report() const
{
	if (format == 'A' || format == 'D')
	{
		sort();
	}
}