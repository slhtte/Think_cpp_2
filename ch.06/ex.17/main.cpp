#include <iostream>
#include <vector>

template <class It1, class It2, class UnPred>
It2 transform_if(It1 begin1, It1 end1, It2 dest, UnPred f)
{
	while (begin1 != end1)
	{
		if (f(*begin1))
		{
			*dest++ = *begin1 * 10;
		}
		++begin1;
	}

	return dest;
}

bool f(int i)
{
	return (i % 3) == 0; 
}

int main()
{
	std::vector<int> v1, v2;

	for (size_t i = 1; i <= 10; ++i)
	{
		v1.push_back(i);
	}

	transform_if(v1.begin(), v1.end(), std::back_inserter(v2), f);

	for (const int &i : v2)
	{
		std::cout << i << std::endl;
	}
}