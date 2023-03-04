#include "reverse_string.h"
#include <iostream>
#include <cctype>
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

void get_input(string& s, int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		s += argv[i];
	}

	string tmp{s};
	s.clear();

	for (const auto& ch : tmp)
	{
		if (isalpha(ch))
		{
			s += ch;
		}
	}
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cerr << "usage: is_palindrom [string]\n";
		exit(EXIT_FAILURE);
	}

	string input;
	get_input(input, argc, argv);
	to_upper(input);

	if (input == reverse_string(input))
	{
		cout << "input is palindrom\n";
	}
	else
	{
		cout << "input is not palindrom\n";
	}

	return 0;
}