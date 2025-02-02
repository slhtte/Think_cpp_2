#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out("data.txt");
	for (size_t i = 0; i < 10000000; ++i)
	{
		out << i << std::endl;
	}
}