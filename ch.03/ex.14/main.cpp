#include <fstream>
#include <string>
#include "../../require.h"

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);

	std::ifstream in(argv[1]);
	assure(in);

	std::string str, res;

	const std::string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .";

	while (getline(in, str))
	{
		int i  = 0;
		while ((i = str.find_first_not_of(ABC, i)) != std::string::npos)
		{
			str.replace(i, sizeof(char), " ");

			if (++i >= str.size())
			{
				break;
			}
		}

		res += str;

		if (str[str.size() - 1] != ' ') res += ' ';
	}

	int i = 0;

	char SPACE = ' ';
	char DOT = '.';

	while ((i = res.find('.', i)) != std::string::npos)
	{
		bool processed = false;
		for (int j = i + 1; j < res.size(); ++j)
		{
			if (res[j] != SPACE && res[j] != DOT)
			{
				res[j] = toupper(res[j]);
				i = j + 1;
				processed = true;
				break;
			}
		}

		if (processed) continue;
		break;
	} 

	std::ofstream out("out");
	out << res;
}