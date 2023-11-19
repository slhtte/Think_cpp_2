#include "Finder.h"
#include <fstream>
#include "../../require.h"

int main(int argc, char *argv[])
{
	requireArgs(argc, 2);
	std::ifstream in(argv[1]);
	assure(in);

	Finder f(in, std::string(argv[2]));
	f.report();
}