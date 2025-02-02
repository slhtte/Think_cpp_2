#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> male = { "Jon Brittle", "Mike Brittle", "George Jensen" };
	std::vector<std::string> female = { "Jane Brittle", "Sharon Brittle", "Evelyn Jensen" };

	std::sort(male.begin(), male.end());
	std::sort(female.begin(), female.end());

	
    
	for (size_t i = 0; i < male.size(); ++i)
	{
	    std::cout << male[i] << " " << female[i] << std::endl;
	}
	std::cout << std::endl;


	while (true)
	{
		if (std::prev_permutation(male.begin(), male.end()) ||
		    std::prev_permutation(female.begin(), female.end()))
		{
		    for (size_t i = 0; i < male.size(); ++i)
	        {
		        std::cout << male[i] << " " << female[i] << std::endl << std::endl;
	        }
	    }
	    else
	    {
	    	break;
	    }
	}

	for (size_t i = 0; i < male.size(); ++i)
	{
	    std::cout << male[i] << " " << female[i] << std::endl;
	}
	std::cout << std::endl;

    while (true)
	{
		if (std::next_permutation(male.begin(), male.end()) &&
		   std::next_permutation(female.begin(), female.end()))
		{
		    for (size_t i = 0; i < male.size(); ++i)
	        {
		        std::cout << male[i] << " " << female[i] << std::endl << std::endl;
	        }
	    }
	    else
	    {
	    	break;
	    }
	}
}