#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iostream>
#include "../../require.h"
#include "../examples/TokenIterator.h"

int main(int argc, char *argv[])
{
    std::string file_name{"main.cpp"};
	
	if (argc > 1)
	{
		file_name = std::string{argv[1]};
	}

    std::ifstream in{file_name};
	assure(in);

	std::string str, res;
	while (in >> str)
	{
		res += str + ' ';
	}

	std::stringstream ss{res};

	using IsbIt = std::istreambuf_iterator<char>;
	IsbIt is_begin{ss}, is_end;
	
	Delimiters 
	delimiters{" \t\n~;()\"<>:{}[]+-=&*#.,/\\"};
	
	TokenIterator<IsbIt, Delimiters> 
	worditer{is_begin, is_end, delimiters},
	end;

	std::list<std::string> lst;

	std::copy(worditer, end, 
		std::back_inserter(lst));

	std::ostream_iterator<std::string> 
	out(std::cout, "\n");

	std::copy(lst.begin(), lst.end(), out);
}