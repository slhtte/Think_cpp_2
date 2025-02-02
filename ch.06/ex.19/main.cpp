#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>

template <class T>
class Generator
{
	std::set<T> s;
	int limit;
public:
	Generator(const size_t &l = 9) : limit(l) {}
	T operator()()
	{
		while (true)
		{
			srand(time(nullptr));
			int tmp = rand() % limit;
			T res = tmp + (T)0.1;
			if (s.find(res) == s.end())
			{
				s.insert(res);
				return res;
			}
		}
	}
};

template <class T>
class Matrix
{
	std::vector<std::vector<T>> m;
	size_t sz;
public:
	Matrix(const size_t &size = 3) : sz(size)
	{
		m.resize(size);
		for (std::vector<T> &line : m)
		{
			std::generate_n(back_inserter(line), size, Generator<T>(size * size));
		}
	}

	friend std::ostream& operator<<(std::ostream &os, const Matrix<T> &m)
	{
        for (const std::vector<T> &line : m.m)
        {
        	for (const T &t : line)
        	{
        		os << t << " ";
        	}

        	os << std::endl;
        }
		return os;
	}

	Matrix operator+(const Matrix<T> &right)
	{
		Matrix<T> res(sz);
		for (size_t i = 0; i < sz; ++i)
		{
			std::transform(m[i].begin(), m[i].end(), right.m[i].begin(), res.m[i].begin(), std::plus<T>());
		}
		return res;
	}

	std::vector<T> operator*(const std::vector<T> &right)
	{
		std::vector<T> res(sz);

		Matrix<T> tmp(sz);
		for (size_t i = 0; i < sz; ++i)
		{
			res[i] = std::inner_product(m[i].begin(), m[i].end(), right.begin(), 0);
		}

		return res;
	}

	Matrix operator*(const Matrix<T> &right)
	{
		Matrix<T> transp = *this;

		for (size_t i = 0; i < sz; ++i)
		{
			for (size_t j = 0; j < sz; ++j)
			{
				transp[i][j] = m[j][i];
			}
		}

		Matrix<T> res(sz);

		for (size_t i = 0; i < sz; ++i)
		{
			res[i].push_back(std::inner_product(m[i].begin));
		}
	}
};

int main()
{
	Matrix<int> m1, m2;
	std::cout << m1 << std::endl;
	std::cout << std::endl;

	std::cout << m2 << std::endl;
	std::cout << std::endl;

	std::cout << m1 + m2 << std::endl;
	std::cout << std::endl;

	std::vector<int> v1 = { 1, 2, 3 };
	std::vector<int> res = m2 * v1;
	std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
}