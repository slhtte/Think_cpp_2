#include <fstream>
#include "Counter.h"
#include "../../require.h"

int main(int argc, char *argv[])
{
	requireArgs(argc, 2);
	std::ifstream in(argv[1]);
	assure(in);

	char format = argv[2][0];

	if (format != 'S' || format != 'A' || format != 'D')
	{
		require(false, "bad format\n");
	}

	Counter c(in, format);
	c.report();
}