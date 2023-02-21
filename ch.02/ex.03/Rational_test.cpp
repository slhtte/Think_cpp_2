#include "Rational_test.h"

int main()
{
	TestSuite::Suite suite{"My_suite"};
	suite.addTest(new Rational_test);
	suite.run();
	suite.report();
	suite.free();
}