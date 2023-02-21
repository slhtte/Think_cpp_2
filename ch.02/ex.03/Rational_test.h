#ifndef _RATIONAL_TEST_H_
#define _RATIONAL_TEST_H_

#include "Rational.h"
#include "../TestSuite/Suite.h"
#include <sstream>

class Rational_test : public TestSuite::Test
{
	Rational r1{1, 2};
	Rational r2{2, 8};
	Rational r3{0, 1};
	Rational r4{2, 4};
	Rational r5{7, 32};

	Rational res_unar_min{-1, 2};
	Rational res_plus{6, 8};
	Rational res_min{2, 8};
	Rational res_mult{2, 16};
	Rational res_del{8, 4};
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

		Rational tmp = r1;
		test_((r1 += r2) == res_plus);
		r1 = tmp;
		test_((r1 -= r2) == res_min);
		r1 = tmp;
		test_((r1 *= r2) == res_mult);
		r1 = tmp;
		test_((r1 /= r2) == res_del);
		r1 = tmp;

		test_(r2 < r1);
		test_(r1 > r3);
		test_(r1 <= r4);
		test_(r2 >= r5);
		test_(r1 == r4);
		test_(r1 != r2);
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