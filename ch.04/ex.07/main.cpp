#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
	std::ifstream in1("data.txt");
	std::ifstream in2("data.txt");
	std::vector<std::string> v_str;
	std::string s;

	while (in1 >> s)
	{
		v_str.emplace_back(s);
	}

	std::stringstream ss;
	ss << in2.rdbuf();

	std::vector<unsigned int> v_i;
	time_t t_i_start, t_i_end;
	time(&t_i_start);
	for (size_t i = 0; i < v_str.size(); ++i)
	{
		v_i.emplace_back(atoi(v_str[i].c_str()));
	}
	time(&t_i_end);

	std::cout << v_i.size() << std::endl;

	std::vector<unsigned int> v_ss;
	unsigned int ui = 0;
	time_t t_ss_start, t_ss_end;
	time(&t_ss_start);
	while (ss >> ui)
	{
		v_ss.emplace_back(ui);
	}
	time(&t_ss_end);

	std::cout << v_ss.size() << std::endl;

	std::cout << t_i_end - t_i_start << std::endl;
	std::cout << t_ss_end - t_ss_start << std::endl;
}