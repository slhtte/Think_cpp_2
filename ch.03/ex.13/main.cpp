#include "../../require.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
	requireArgs(argc, 2);
	std::ifstream in(argv[1]);
	assure(in);

	std::string search(argv[2]);
	std::vector<std::string> words;
	std::string str;
	while (getline(in, str))
	{
		std::stringstream ss(str);

		std::string tmp;
		while (ss >> tmp)
		{
			words.push_back(tmp);
		}
	}

	std::string all_words;
	for (const auto &word : words)
	{
		all_words += word + " ";
	}

	size_t first_find = all_words.find(search);
	int first_find_index = -1;

	if (first_find != std::string::npos)
	{
		size_t sizes = 0;
		for (int i = 0; i < words.size(); ++i)
		{
			if (first_find > sizes)
			{
			    sizes += words[i].size() + 1;
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
	int first_rfind_index = -1;

	if (first_rfind != std::string::npos)
	{
		if (first_rfind == first_find)
		{
			first_rfind_index = first_find_index;
		}
		else
		{
		    size_t sizes = all_words.length();
		    for (int i = words.size(); i >= 0; --i)
		    {
			    if (first_rfind < sizes)
			    {
				    sizes -= words[i - 1].length() + 1;
			    }
			    else if (first_rfind >= sizes)
			    {
				    first_rfind_index = i;
				    break;			
			    }
		    }
		}
	}

	int first_not_find_index = -1;
	int first_not_rfind_index = -1;

		for (int i = 0; i < words.size(); ++i)
		{
			if (i != first_find_index && i != first_rfind_index)
			{
				first_not_find_index = i;
				break;
			}
		}

		for (int i = words.size() - 1; i >= 0; --i)
		{
			if (i != first_rfind_index && i != first_find_index)
			{
				first_not_rfind_index = i;
				break;
			}
		}

	if (first_find == std::string::npos && first_not_find_index == -1)
	{
		std::cout << "Not found\n";
		return 0;
	}
	
	if (first_find != std::string::npos)
	{
		std::cout << "first find string:  [" << first_find_index << "] " << words[first_find_index] << std::endl
		          << "first rfind string: [" << first_rfind_index << "] " << words[first_rfind_index] << std::endl;
	}

	if (first_not_find_index != -1)
	{
		std::cout << "first not find string:  [" << first_not_find_index << "] " << words[first_not_find_index] << std::endl
                  << "first not rfind string: [" << first_not_rfind_index << "] " << words[first_not_rfind_index] << std::endl;		
	}

}