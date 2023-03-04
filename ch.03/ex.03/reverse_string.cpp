#include "reverse_string.h"

std::string reverse_string(const std::string& s)
{
	std::string str{s};

	for (auto i = 0; i <= (str.size() - 1) / 2; ++i)
	{
		std::swap(str[i], str[str.size() - 1 - i]);
	}

	return str;
}