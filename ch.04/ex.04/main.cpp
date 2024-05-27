#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "../../require.h"

int main(int argc, char *argv[])
{
	requireMinArgs(argc, 1);
	std::ifstream in(argv[1]);
	assure(in, argv[1]);

    std::set<std::string> s;
    std::string str;
    while (getline(in, str))
    {
    	size_t pos = str.find(":");
    	if (pos != std::string::npos)
    	{
    		s.emplace(str.substr(0, pos));
    	}
    }

    for (auto it = s.begin(); it != s.end(); ++it)
    {
    	system(std::string("gvim " + *it).c_str());
    }
}