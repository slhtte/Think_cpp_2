#ifndef _RATIONAL_TEST_H_
#define _RATIONAL_TEST_H_

#include "../ex.02/Rational.h"
#include "../../listings/TestSuite/Test.h"

class Rational_test : public TestSuite::Test
{
	Rational r1(4, 1000);
	Rational r2(16, 100000);
	Rational r3(0, 1);
	Rational r4(40, 10000);

	Rational res_unar_min(-4, 1000);
	Rational res_plus(416, 100000);
	Rational res_min(385, 100000);
	Rational res_mult(64, 100000000);
	Rational res_del(100, 4);
public:
	void run()
	{
		test_(-r1 == res_unar_min);
		test_(r1 + r2 == res_plus);
		test_(r1 - r2 == res_min);
		test_(r1 * r2 == res_mult);
		test_(r1 / r2 == res_del);
	}
};

#endif