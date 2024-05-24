#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "../../require.h"

int main()
{
	std::ifstream in("main.cpp");
	assure(in, "main.cpp");

	std::ostringstream os;
	os << in.rdbuf();
	std::istringstream is{os.str()};

	std::string s;

	getline(is, s);

	for (auto &ch : s)
	{
		ch = toupper(ch);
	}

	std::ofstream out("out.txt");
	assure(out, "out.txt");
	out << s << std::endl;
}