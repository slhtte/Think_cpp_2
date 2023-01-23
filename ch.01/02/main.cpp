#include <iostream>
using namespace std;

class Base
{
public:
	class BaseException 
	{
		const char *msg;
	public:
		BaseException(const char *m) : msg(m) {}
		const char* what() { return msg; }
	};

	void func() throw(BaseException)
	{
		throw BaseException("exception");
	}
};

int main()
{
	try
	{
		Base b;
		b.func();
	}
	catch (Base::BaseException& e)
	{
		cout << e.what() << endl;
	}
}