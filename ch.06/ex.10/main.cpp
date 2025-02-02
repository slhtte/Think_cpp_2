#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <iostream>


std::string str_to_lowercase(std::string &s)
{
	for (char &c : s)
	{
		c = tolower(c);
	}
	return s;
}

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	std::string str;
	std::vector<std::string> v;

	while (in >> str)
	{
		v.push_back(str);
	}

    std::transform(v.begin(), v.end(), v.begin(), std::ptr_fun(str_to_lowercase));
    std::sort(v.begin(), v.end());

    std::vector<std::string> u;
    std::unique_copy(v.begin(), v.end(), std::back_inserter(u));
    std::copy(u.begin(), u.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}