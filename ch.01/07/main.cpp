#include <iostream>
using namespace std;

class My_exception
{
public:
	My_exception(const char *msg)
	{
		cout << "~My_exception(): " << msg << endl;
	}
	~My_exception()
	{
		cout << "~My_exception()\n";
	}
};

int main()
{
	try
	{
		throw My_exception("inside try...");
	}
	catch(...)
	{
		cout << "inside catch...\n";
	}

	cout << "before exit...\n";
}