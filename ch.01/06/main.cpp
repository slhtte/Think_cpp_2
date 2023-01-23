#include <iostream>
using namespace std;

void my_terminate()
{
	cout << "my_terminate()\n";
	exit(0);
}

void (*old_term)() = set_terminate(my_terminate);

class My
{
public:
	void func() throw(int)
	{
		cout << "inside func()\n";
		throw 1;
	}

	~My()
	{
		cout << "inside ~My()\n";
		func();
	}
};

int main()
{
	try
	{
		My my;
		my.func();
	}
	catch(...)
	{
		cout << "inside catch\n";
	}
}