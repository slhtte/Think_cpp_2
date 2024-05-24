#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../../require.h"

int main(int argc, char **argv)
{
	requireMinArgs(argc, 2);
	std::ifstream in(argv[1]);
	assure(in, argv[1]);

	std::vector<std::string> v;
	for (int i = 2; i < argc; ++i)
	{
		v.emplace_back(argv[i]);
	}

	std::string s;
	std::ofstream out("out.txt");
	assure(out, "out.txt");
	int count = 0;
	while (getline(in, s))
	{
		++count;
		for (const auto &str : v)
		{
			bool found = false;
			if (s.find(str) != std::string::npos)
			{
				out << count << " : " << s << std::endl;
				found = true;
			}

			if (found)
			{
				break;
			}
		}
	}
}
