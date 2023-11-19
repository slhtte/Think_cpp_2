#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <fstream>
#include <vector>

class Couner
{
	const size_t OFFSET = 32;
	const size_t ARR_SIZE = 95;
	size_t arr_code[ARR_SIZE];
	std::vector<size_t> sorting; 
	char format;

    void sort();
public:
	Counter(const std::ifstream &file, const char format);
	void report() const;
}

#endif