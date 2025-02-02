#include <iostream>
#include <vector>
#include <algorithm>

class B
{
public:
	virtual void f()
	{
		std::cout << "void B::f()\n";
	}
};

class D : public B
{
public:
	virtual void f() override
	{
		std::cout << "void D::f()\n";
	}
};

int main()
{
	std::vector<B*> v;
	v.push_back(new B);
	v.push_back(new D);
	v.push_back(new B);
	v.push_back(new D);

	std::for_each(v.begin(), v.end(), std::mem_fun(&B::f));
}