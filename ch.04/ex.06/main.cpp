#include <iostream>
#include <fstream>

int main()
{
	try
	{
		std::fstream str("main.cpp");
		str.clear(std::ios::badbit);
		str.exceptions(std::ios::badbit);
	}
/*	catch (const std::ios::failure &fail)
	{
		std::cout << "std::ios::failure\n";
	}
*/
	catch (const std::exception &ex)
	{
		std::cout << "std::exception\n";
	}
}