//@copyright
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../require.h"

const std::string COPYRIGHT = "//@copyright";

void add_copyright(std::ifstream &in, const std::string &name)
{
    std::string str;
	if (getline(in, str))
	{
		if (str.find(COPYRIGHT) == std::string::npos)
		{
			std::stringstream ss;
			ss << COPYRIGHT + "\n" + str + "\n";
			ss << in.rdbuf();

			in.close();
			system(std::string("rm  " + name).c_str());

			std::ofstream out(name);
			assure(out, name);

			out << ss.rdbuf();
		}
	}
}

int main(int argc, char *argv[])
{
	requireMinArgs(argc, 1);
	std::ifstream in(argv[1]);
	assure(in, argv[1]);

	add_copyright(in, argv[1]);
}