#ifndef _RATIONAL_TEST_H_
#define _RATIONAL_TEST_H_

#include "Rational.h"
#include "../TestSuite/Test.h"
#include <sstream>

class Rational_test : public TestSuite::Test
{
	Rational r1{1, 2};
	Rational r2{2, 3};
	Rational r3{0, 1};
	Rational r4{40, 10000};

	Rational res_unar_min{-1, 2};
	Rational res_plus{7, 6};
	Rational res_min{-1, 6};
	Rational res_mult{2, 6};
	Rational res_del{3, 4};
	Rational res_istream{4, 8};
public:
	
	void run()
	{
		test_(-r1 == res_unar_min);
		test_(r1 + r2 == res_plus);
		test_(r1 - r2 == res_min);
		test_(r1 * r2 == res_mult);
		test_(r1 / r2 == res_del);

		Rational tpm_res_istream = __test_input();
		test_(res_istream == tpm_res_istream);
		std::string tmp_res_output = __test_output();
		test_(tmp_res_output == "0.5 * 10 ^ (0)");
	}

private:
	Rational __test_input()
	{
		Rational res;

		while (true)
		{
		    try
		    {
		        std::cout << "Please, input d for denormalize and n for normalize form of number 4/8:" << std::endl;
		        res = Rational(0, 1);
		        std::cin >> res;
		        break;
		    }
		    catch (Rational::Rational_Exception &e)
		    {
			    std::cout << e.what() << std::endl;
		    }
		}


		return res;
	}

	std::string __test_output()
	{
		std::stringstream ss;
		ss << res_istream;
		return ss.str();
	}
};

#endif