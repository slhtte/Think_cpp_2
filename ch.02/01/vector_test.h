#ifndef _VECTOR_TEST_H_
#define _VECTOR_TEST_H_

#include <vector>
#include "../../listings/TestSuite/Test.h"

class Vector_test : public TestSuite::Test
{
	std::vector<int> v;
public:
	void test_push_back()
	{
		v.push_back(1);
		test_(v[0] == 1);
		v.push_back(2);
		test_(v[1] == 2);
	}
	void test_pop_back()
	{
		v.pop_back();
		test_(v.size() == 1);
	}
	void test_exception()
	{
		try
		{
			v.at(0);
			fail_("Invalid argument of at()");
		}
		catch(std::out_of_range&)
		{
			succeed_();
		}
	}
	void run()
	{
		test_push_back();
		test_(v.front() == 1);
		test_(v.back() == 2);
		test_pop_back();
		test_(v.at(0) == 1);
		test_(v.size() == 1);
		test_exception();
	}
};

#endif