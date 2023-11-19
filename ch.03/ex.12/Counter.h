#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <fstream>
#include <vector>

class Counter
{
	struct Pair
	{
		unsigned short code;
		size_t matches;

		Pair(const unsigned short c = 0, const size_t m = 0) : code(c), matches(m) {}
		bool operator<(const Pair &other) const;
	};

	const size_t OFFSET = 32;
	const unsigned short ARR_SIZE = 95;
	size_t *arr_code;
	std::vector<Pair> sorting; 
	char format;

    void sort();
public:
	Counter(std::ifstream &file, const char format);
	void report();
};

#endif