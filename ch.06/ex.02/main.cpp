#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <iterator>

int main()
{
	std::string str{"samoLeT"};
	std::transform(str.begin(), str.end(), str.begin(), std::ptr_fun(toupper));
	std::copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout, ""));
	std::cout << std::endl;
}