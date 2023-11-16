#include <fstream>
#include <string>
#include "../../require.h"
#include "Finder.h"

int main(int argc, char *argv[])
{
	requireMinArgs(argc, 3);
	
	std::ifstream in(argv[1]);
	assure(in);

	Finder f(argc, argv);
	f.report();
}