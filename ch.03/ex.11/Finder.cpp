#include "Finder.h"
#include <sstream>
#include <iostream>

Finder::Finder(std::ifstream &in, const std::string &str)
{
	std::string buf;
	while (getline(in, buf))
	{
		std::stringstream stream(buf); // inininininininininininininininininin
		std::string word;

		while (stream >> word)
		{
			bool first_found = true;
			size_t i = 0;
			while (true)
			{
				i = word.find(str, i);

				if (i != std::string::npos)
				{
					++match_count;

					if (first_found)
					{
						words.emplace_back(word);
						first_found = false;
					}

					i += str.size();
				}
				else
				{
					break;
				}
			}
		}
    }
}

void Finder::report() const
{
    size_t all_size = 0;

    for (size_t i = 0; i < words.size(); ++i)
    {
    	all_size += words[i].size();
    }
	size_t average_size = all_size / words.size();

	if (match_count > 0)
	{
		std::cout << "match count: " << match_count << std::endl
		          << "average word size: " << average_size << std::endl;
	}
}