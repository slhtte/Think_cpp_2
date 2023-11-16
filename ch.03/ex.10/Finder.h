#ifndef _FINDER_H_
#define _FINDER_H_

#include <vector>
#include <string>

class Finder
{
public:
	enum mode_e 
	{
		AT_LEAST_ONE = 0,
		BOTH,
		NO_ONE,
		INVALID
	};

private:
	std::vector<std::string> __report1;
	std::vector<std::string> __report2;
	std::string __s1;
	std::string __s2;
	mode_e __mode;
public:
	Finder(int argc, char *argv[]);
	void report();

private:
	mode_e __get_mode(int argc, char *argv[]);
	void __find_strings(char *argv[]);
	std::string __without_delim(char *argv);
};

#endif