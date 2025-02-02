#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(size_t &count, const std::vector<std::string> &v)
{
	std::cout << "[" << count++ << "]: ";
	for (const std::string &s : v)
	{
		 std::cout << s << " ";
	}

	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::vector<std::string> v(argc - 1);

	for (size_t i = 1; i <= v.size(); ++i)
	{
		v[i - 1] = argv[i];
	}

	std::vector<std::string> copy = v;

	size_t count = 0;

	while (std::next_permutation(v.begin(), v.end()))
	{
		print(count, v);
	}

	print(++count, copy);

	while (std::prev_permutation(copy.begin(), copy.end()))
	{
		print(count, copy);
	}
}