#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <fstream>
#include <vector>

class Counter
{
	struct Pair
	{
		unsigned short code;
		unsigned matches;

		Pair(const unsigned short c = 0, const unsigned m = 0) : code(c), matches(m) {}
		bool operator<(const Pair &other) const;
	};

	const unsigned short OFFSET = 32;
	const unsigned short ARR_SIZE = 95;
	unsigned *arr_code;
	std::vector<Pair> sorting; 
	char format;

    void sort();
public:
	Counter(std::ifstream &file, const char format);
	void report();
};

#endif