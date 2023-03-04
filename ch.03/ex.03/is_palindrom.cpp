#include "reverse_string.h"
#include <iostream>
using namespace std;

bool is_palindrom(const string& s)
{
	return s == reverse_string(s);
}

string& to_upper(string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		s[i] = toupper(s[i]);
	}

	return s;
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cerr << "usage: is_palindrom [string]\n";
		exit(EXIT_FAILURE);
	}

	string input(argv[1]);
	string copy_input{input};

	if (to_upper(input) == reverse_string(to_upper(input)))
	{
		cout << copy_input << " is palindrom\n";
	}
	else
	{
		cout << copy_input << " is not palindrom\n";
	}

	return 0;
}