#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <numeric>
#include <cmath>

struct Gen
{
	std::set<int> s;
	int operator()()
	{
		srand(time(nullptr));

		while(true)
		{ 
			int res;
			if (rand() % 10 == 0)
		    {
			    res = rand() % 100;
		    }
		    else
		    {
		        res = rand() % 10 + 10;
		    }

		    if (s.find(res) == s.end())
		    {
		    	s.insert(res);
		    	return res;
		    }
		}
	}
};

struct Un_func
{
	int average;
	int res;
	Un_func(const int a = 0) : average(a), res(0) {;}
	int operator()(const int i)
	{
		res += (i - average) * (i - average);
		return res;
	}
};

class Anomaly_finder
{
	int average = 0;
	double sigma = 0;
public:
	Anomaly_finder(const std::vector<int> &v)
	{
		average = std::accumulate(v.begin(), v.end(), 0) / v.size();
		Un_func f;
		f = std::for_each(v.begin(), v.end(), f);
		sigma = sqrt((double)f.res / v.size());
	}

	bool operator()(const int i)
	{
		return i < average - sigma / 2 || i > average + sigma / 2;
	}
};

struct Aver
{
	float res = 0;
	int count = 0;
	int incr = 0;
	void operator()(const int i)
	{
		incr += i;
		++count;
		res = float(incr) / count;
	}
};



int main()
{
	std::vector<int> v;
	std::generate_n(back_inserter(v), 50, Gen());
	std::sort(v.begin(), v.end());

	for (const int &i : v)
	{
		std::cout << i << std::endl;
	}

	std::cout << "================================\n";

	Anomaly_finder f(v);

	std::vector<int> res;
	std::remove_copy_if(v.begin(), v.end(), back_inserter(res), f);

	for (const int &i : res)
	{
		std::cout << i << std::endl;
	}

	std::cout << "================================\n";

	Aver a;
	std::cout << std::for_each(res.begin(), res.end(), a).res << std::endl;
}