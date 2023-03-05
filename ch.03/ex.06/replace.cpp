#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string get_string(ifstream& file)
{
	string line, result;

	while (getline(file, line))
	{
		result += line + " ";
	}

	file.close();

	return result;
}

string replace_string(ifstream& file, const string& from, const string& to)
{
	string source(get_string(file));

	size_t lookHere{0}, foundHere{0};

	while ((foundHere = source.find(from, lookHere)) != string::npos)
	{
		source.replace(foundHere, from.size(), to);
		lookHere = foundHere + to.size();
	}

	return source;
}

void print_file(ifstream& file)
{
	string line;

	while (getline(file, line))
	{
		cout << line << endl;
	}
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		cerr << "usage ./replace <file_path> <string from> <string to>\n";
		exit(EXIT_FAILURE);
	}

    ifstream file(argv[1]);
	if (!file)
	{
		cerr << "error opening file\n";
		exit(EXIT_FAILURE);
	}

	string result_string = replace_string(file, argv[2], argv[3]);

	ofstream ofile(argv[1]);
	ofile << replace_string;
	ofile.close();

	ifstream ifile(argv[1]);
	print_file(ifile);
	ifile.close();
}