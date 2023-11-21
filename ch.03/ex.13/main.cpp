#include "../../require.h"
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[])
{
	requireArgs(argc, 2);
	std::ifstream in(argv[1]);
	assure(in);

	std::string search(argv[2]);
	std::vector<std::string> words;
	std::string str;
	size_t words_size = 0;
	while (getline(in, str))
	{
		std::stringstream ss(str);

		std::string tmp;
		while (ss >> tmp)
		{
			words.push_back(tmp);
			words_size += tmp.length();
		}
	}

	std::string all_words;
	for (const auto &word : words)
	{
		all_words += word + " ";
	}

	size_t first_find = all_words.find(search);
	int first_find_index = -1;
	int first_not_find_index = -1;

	if (first_find != std::string::npos)
	{
		size_t sizes = 0;
		for (int i = 0; i < words.size(); ++i)
		{
			if (first_find > sizes)
			{
			    sizes += words[i].size() + 1;
			    first_not_find_index = i;
			}
			else if (first_find < sizes)
			{
				first_find_index = i - 1;
				break;
			}
			else
			{
				first_find_index = i;
				break;
			}
		}
	}

	size_t first_rfind = all_words.rfind(search);
	size_t first_rfind_index = 0;
	int first_not_rfind_index

	if (first_rfind != std::string::npos)
	{
		size_t sizes = words_size - words[words.size() - 1].size() - 1;
		for (int i = words.size() - 1; i >= 0; ++i)
		{
			if (first_rfind < sizes)
			{
				sizes -= words[i].size() + 1;

			}
			else if (first_rfind >= sizes)
			{
				first_rfind_index = i;
				break;			
			}
		}
	}

    std::string first_find_str;
    std::string first_rfind_str;
    std::string first_not_find_str;
    std::string first_not_rfind_str;
}