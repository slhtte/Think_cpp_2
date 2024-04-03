#include "../../require.h"
#include <fstream>
#include <string>
#include <iostream>

int round_up(int *numbs, int index, int max_index)
{
	if (numbs[index] >= 5) return 1;
	else if (numbs[index] < 5 && index == max_index) return 0;
	else if (numbs[index] < 5 && index < max_index)
	{
		
	}
}

int main(int argc, char *argv[])
{
	requireArgs(argc, 1);

	std::ifstream in(argv[1]);
	assure(in);

	const std::string NUM = "0123456789";
	std::string str, res;
	while (getline(in, str))
	{
		res += str + ' ';
	}

	int i = 0;
	while ((i = res.find_first_of(NUM, i)) != std::string::npos)
	{
	    res.insert(i, "$");

	    int j = res.find(".", i + 1);
	    int first_dot = j + 1;
	    j = res.find_first_not_of(NUM + ".", j + 1);
        
        std::string mixed(res.substr(first_dot, j - first_dot));
        std::cout << mixed << std::endl;


        int *numbs = new int[mixed.size()];
        int numbs_index = 0 ;
        for (int n = 0; n < mixed.size(); ++n)
        {
        	if (mixed[n] != '.')
        	{
        		numbs[numbs_index++] = mixed[n] - '0';
        	}
        }

        if (numbs_index > 1)
        {
        	std::string first_numbs{ std::to_string(numbs[0]) + std::to_string(numbs[1]) };

        	int curr_numb = 2;

        	numbs[curr_numb] += round_up(numbs, curr_numb, numbs_index);
        }



	    i = j + 1;
	}

	std::cout << res << std::endl;
}