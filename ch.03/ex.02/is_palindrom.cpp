#include "reverse_string.h"
#include <iostream>
using namespace std;

bool is_palindrom(const string& s)
{
	return s == reverse_string(s);
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cerr << "usage: is_palindrom [string]\n";
		exit(EXIT_FAILURE);
	}

	string input(argv[1]);

	if (input == reverse_string(input))
	{
		cout << input << " is palindrom\n";
	}
	else
	{
		cout << input << " is not palindrom\n";
	}

	return 0;
}