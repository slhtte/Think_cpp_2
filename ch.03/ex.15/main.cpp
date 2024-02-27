#include "../../require.h"
#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	requireArgs(argc, 1);

	std::ifstream in(argv[1]);
	assure(in);

	const std::string NUM = "0123456789";
	std::string str, res;
	while (getline(in, str))
	{
		res += str + ' ';
	}

	int i = 0;
	i = res.find_first_of(NUM, i);
	/*while ((i = res.find_first_of(NUM, i)) != std::string::npos);
	{
	    res.insert(i, "$");

	    int j = res.find(".", i + 1);
	    j = res.find_first_not_of(NUM + ".", j + 1);
	    i += j + 1;
	}*/

	std::cout << res << std::endl;
}