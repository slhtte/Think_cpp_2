#include "reverse_string.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool is_palindrom(const string& s)
{
	return s == reverse_string(s);
}

string to_upper(const string& s)
{
	string result{s};

	for (int i = 0; i < s.size(); ++i)
	{
		result[i] = toupper(s[i]);
	}

	return result;
}

vector<string> read_file(fstream& f)
{
	string str;
	vector<string> result;

	while (f >> str)
	{
		result.push_back(str);
	}

	return result;
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cerr << "usage: is_palindrom [file]\n";
		exit(EXIT_FAILURE);
	}

	fstream in(argv[1]);
	if (!in)
	{
		cerr << "error opening file\n";
		exit(EXIT_FAILURE);
	}

	vector<string> content = read_file(in);
	string out;

	for (const auto& str : content)
	{
		if (is_palindrom(to_upper(str)))
		{
			if (out.find(to_upper(str)) == string::npos)
			{
				cout << str << endl;
				out += to_upper(str) + ' ';
			}
		}

	}

	return 0;
}