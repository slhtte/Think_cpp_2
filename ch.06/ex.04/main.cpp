#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

size_t factorial(size_t n)
{
	if (n == 1)
	{
		return 1;
	}

	return n * factorial(n - 1);
}

char get_b(char c)
{
	if (c == 'c' || c == 'd' || c == 'e')
	{
	    return 'b';
	}

	return c;
}

int main(int argc, char *argv[])
{
	std::string str = argv[1];
	std::string str_unique{};
	std::sort(str.begin(), str.end());
	std::unique_copy(str.begin(), str.end(), std::back_inserter(str_unique));
	size_t SIZE = factorial(str.length()) / factorial(str.length() - str_unique.length() + 1);
	std::vector<std::string> v(SIZE);

	size_t count = 0;
	while (count < v.size())
	{
		std::random_shuffle(str.begin(), str.end());
		std::vector<std::string>::iterator end_v = v.begin() + count;
		if (std::find(v.begin(), end_v, str) == end_v)
		{
			v[count++] = str;
		}
	}


	//for (std::string &s : v)
	//{
	//	std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun(get_b));
	//}

	//std::vector<std::string> v_copy;
	std::sort(v.begin(), v.end());
	//std::unique_copy(v.begin(), v.end(), std::back_inserter(v_copy));
	//std::sort(v_copy.begin(), v_copy.end());

	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << "[" << i << "]: " << v[i] << std::endl;
	}
}