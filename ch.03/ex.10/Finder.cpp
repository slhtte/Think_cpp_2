#include "Finder.h"
#include <fstream>
#include <iostream>
#include "../../require.h"
using std::ifstream;

Finder::Finder(int argc, char *argv[])
{
	__mode = __get_mode(argc, argv);
	__find_strings(argv);
}

void Finder::report()
{
	switch (__mode)
	{
		case AT_LEAST_ONE:
		{
			if (__report1.size() != 0)
			{
				std::cout << __s1 << std::endl;
				
				for (size_t i = 0; i < __report1.size(); ++i)
				{
					std::cout << "\t\t";
					std::cout << __report1[i] << std::endl;
				}
			}

			if (__report2.size() != 0)
			{
				std::cout << __s2 << std::endl;

				for (size_t i = 0; i < __report2.size(); ++i)
				{
					std::cout << "\t\t";
					std::cout << __report2[i] << std::endl;
				}
			}

			break;
		}
		case BOTH:
		{
			if (__report1.size() != 0)
			{
			    std::cout << __s1 << " && " << __s2 << std::endl;

			    for (size_t i = 0; i < __report1.size(); ++i)
			    {
			        std::cout << "\t\t";
					std::cout << __report1[i] << std::endl;
			    }
			}

			break;
		}
		case NO_ONE:
		{
			if (__report2.size() != 0)
			{
			    std::cout << "no " << __s1 << " && no " << __s2 << std::endl;

			    for (size_t i = 0; i < __report2.size(); ++i)
			    {
			        std::cout << "\t\t";
					std::cout << __report2[i] << std::endl;
			    }
			}
			break;
		}
		default:
		{
			std::cout << "wrong mode\n";
		}
	}
}

Finder::mode_e Finder::__get_mode(int argc, char *argv[])
{
	if (argc < 5)
	{
		return AT_LEAST_ONE;
	}
	else
	{
		std::string mode(argv[4]);

		if (mode == "-o")
		{
			return AT_LEAST_ONE;
		}
		else if (mode == "-b")
		{
			return BOTH;
		}
		else if (mode == "-n")
		{
			return NO_ONE;
		}
		else
		{
			return INVALID;
		}
	}
}

void Finder::__find_strings(char *argv[])
{
	std::vector<std::string> file;
	__s1 = __mode == NO_ONE ? argv[2] : __without_delim(argv[2]);
	__s2 = __mode == NO_ONE ? argv[3] : __without_delim(argv[3]);
	std::string str;
	ifstream in(argv[1]);
	while (getline(in, str))
	{
		size_t i = str.find(__s1);
		size_t j = str.find(__s2);

		switch (__mode)
		{
			case AT_LEAST_ONE:
			{
				if (i != std::string::npos)
				{
					__report1.emplace_back(str);
				}

				if (j != std::string::npos)
				{
					__report2.emplace_back(str);
				}

				break;
			}
			case BOTH:
			{
				if (i != std::string::npos && j != std::string::npos)
				{
					__report1.emplace_back(str);
				}
				break;
			}
			case NO_ONE:
			{
				if (i == std::string::npos && j == std::string::npos)
				{
					__report2.emplace_back(str);
				}
				break;
			}
			default: break;
		}
	}
}

std::string Finder::__without_delim(char *argv)
{
	std::string str(argv);
	require(str[0] == '*' && str[str.size() - 1] == '*');
	str.erase(0, 1);
	str.erase(str.size() - 1);

	return str;
}