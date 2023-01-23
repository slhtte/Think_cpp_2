#ifndef _VECTOR_TEST_H_
#define _VECTOR_TEST_H_

#include <vector>
#include <stdexcept>
#include "../TestSuite/Test.h"

class VectorTest : public TestSuite::Test
{
	std::vector<int> start;
	int front_start;
	int back_start;

public:
	VectorTest() : start({ 1, 2, 3 }) {}

	void run()
	{
		testFunc();
		testException();
	}

	void testFunc()
	{
		test_(start.size() == 3);
		test_(start.front() == 1);
		test_(start.back() == 3);

		start.pop_back();

		test_(start.size() == 2);
		test_(start.back() == 2);
		test_(start.at(0) == 1);
	}

	void testException()
	{
		try
		{
			std::vector<int> v = { 4, 5, 6 };
			int f = v.at(3);
			fail_("Invalid call vector::at()");
		}
		catch(std::out_of_range&)
		{
			succeed_();
		}
	}
};

#endif