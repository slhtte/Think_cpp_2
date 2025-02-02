#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

class Vocab
{
	const std::string CHAR_SET = "~`!@#%^&*()_-+=}{[]\\:;\"\'<.>?/";
	std::map<std::string, std::string> words;
	std::set<std::string> cripts;

public:
	std::string generate_record(const std::string &s)
	{
		if (words.find(s) == words.end())
		{
			words.emplace(s, "");
			srand(time(nullptr));

			while (true)
			{
				int i = rand() % CHAR_SET.size();
				std::string cript = CHAR_SET.substr(0, i);
				std::random_shuffle(cript.begin(), cript.end());

				if (cripts.find(cript) == cripts.end())
				{
					cripts.insert(cript);
					words[s] = cript;
					return cript;
				}
			}
		}

		return words[s];
	}

	std::string generate_encr(std::string &s)
	{
		if (cripts.find(s) != cripts.end())
		{
			for (std::map<std::string, std::string>::iterator it = words.begin();
				 it != words.end(); ++it)
			{
				if (it->second == s)
				{
					return it->first;
				}
			}
		}

		abort();
	}
};

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	std::ofstream out(std::string(argv[1]) + ".out");
	
    std::string s;
    Vocab v; 
	while (in >> s)
	{
		out << v.generate_record(s) << " ";
	}

	out << std::endl;
	in.close();
	out.close();

	std::ifstream in2(std::string(argv[1]) + ".out");
	std::ofstream out2(std::string(argv[1]) + ".encr");

	while (in2 >> s)
	{
		out2 << v.generate_encr(s) << " ";
	}
	out2 << std::endl;
}