#include "Rational.h"
#include <cassert>
#include <cmath>
#include <iostream>

Rational::Rational(int numerator, int denominator) : m(0), q(0)
{
	assert(denominator != 0);
	m = (double)numerator / (double)denominator;
	__normalize();
}

void Rational::__normalize()
{
	if (m == 0)
	{
		q = 0;
		return;
	}

	if (std::abs(m) >=1 )
	{
		while (std::abs(m) >= 1)
		{
			m /= 10.0;
			++q;
		}
	}
	else if (std::abs(m) < 0.1)
	{
		while (std::abs(m) < 0.1)
		{
			m *= 10;
			--q;
		}
	}
}

double Rational::__denormalize() const
{
	return m * (pow(10, q));
}

Rational Rational::operator-() const
{
	Rational tmp;
	tmp.m = -1 * m;
	tmp.q = q;
	return tmp;
}

Rational operator+(const Rational& left, const Rational& right)
{
	Rational tmp;
	tmp.m = left.__denormalize() + right.__denormalize();
	tmp.__normalize();
	return tmp;
}

Rational operator-(const Rational& left, const Rational& right)
{
	Rational tmp;
	tmp.m = left.__denormalize() - right.__denormalize();
	tmp.__normalize();
	return tmp;
}

Rational operator*(const Rational& left, const Rational& right)
{
	Rational tmp;
	tmp.m = left.m * right.m;
	tmp.q = left.q + right.q;
	tmp.__normalize();
	return tmp;
}

Rational operator/(const Rational& left, const Rational& right)
{
	if (right.m == 0) throw Rational::Rational_Exception("devide by zero");
	
	Rational tmp;
	tmp.m = left.m / right.m;
	tmp.q = left.q - right.q;
	tmp.__normalize();
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	if (r.m == 0)
	{
		os << "0.0";
	}
	else
	{
	    os << r.m << " * 10 ^ (" << r.q << ")"; 
	}

	return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
	char type;
	is >> type;
	if (type == 'n')
	{
	    double m;
	    is >> m;
	    if (m == 0)
	    {
		    r.m = 0;
		    r.q = 0;
	    }
	    else
	    {
	        r.m = m;
	        is >> r.q;
	        r.__normalize();
	    }
	}
	else if (type == 'd')
	{
		int n;
		int d;
		is >> n;
		is >> d;
		Rational tmp(n, d);
		r.m = tmp.m;
		r.q = tmp.q;
	}

	return is;
}

Rational& Rational::operator+=(const Rational& right)
{
	m = __denormalize() + right.__denormalize();
	q = 0;
	__normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& right)
{
	m = __denormalize() - right.__denormalize();
	q = 0;
	__normalize();
	return *this;
}

Rational& Rational::operator*=(const Rational& right)
{
	if (right.m == 0)
	{
		m = 0;
		q = 0;
	}
	else
	{
	    m *= right.m;
	    q += right.q;
	    __normalize();
	}
	return *this;
}

Rational& Rational::operator/=(const Rational& right)
{
	if (right.m == 0) throw Rational_Exception("devide by zero");

	m /= right.m;
	q -= right.q;
	__normalize();
	
	return *this;
}

bool operator<(const Rational& left, const Rational& right)
{
	return left.__denormalize() < right.__denormalize();
}

bool operator>(const Rational& left, const Rational& right)
{
	return left.__denormalize() > right.__denormalize();
}

bool operator<=(const Rational& left, const Rational& right)
{
	return left.__denormalize() <= right.__denormalize();
}

bool operator>=(const Rational& left, const Rational& right)
{
	return left.__denormalize() >= right.__denormalize();
}

bool operator==(const Rational& left, const Rational& right)
{
	return left.m == right.m && left.q == right.q;
}

bool operator!=(const Rational& left, const Rational& right)
{
	return left.m != right.m || left.q != right.q;
}