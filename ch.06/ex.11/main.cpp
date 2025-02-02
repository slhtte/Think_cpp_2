#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main(int argc, char *argv[])
{
	std::ifstream file1(argv[1]);
	std::ifstream file2(argv[2]);

	std::string str;
	std::vector<std::string> v1;

	while (file1 >> str)
	{
		v1.push_back(str);
	}

	std::vector<std::string> v2;

	while (file2 >> str)
	{
		v2.push_back(str);
	}

	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
		                  std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << "\n==================================\n";

	std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
		                          std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << "\n==================================\n";

	std::set_intersection(std::istream_iterator<std::string>(file1),
		                  std::istream_iterator<std::string>(),
		                  std::istream_iterator<std::string>(file2),
		                  std::istream_iterator<std::string>(),
		                  std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << "\n==================================\n";

	std::set_symmetric_difference(std::istream_iterator<std::string>(file1),
		                          std::istream_iterator<std::string>(),
		                          std::istream_iterator<std::string>(file2),
		                          std::istream_iterator<std::string>(),
		                          std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << std::endl;
}