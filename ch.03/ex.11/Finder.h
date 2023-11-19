#ifndef _FINDER_H_
#define _FINDER_H_

#include <fstream>
#include <string>
#include <vector>

class Finder
{
	size_t match_count = 0;
	std::vector<std::string> words;
public:
	Finder(std::ifstream &in, const std::string &str);
	void report() const;
};

#endif