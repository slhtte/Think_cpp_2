#include <iostream>
using namespace std;

class My_exception
{
public:
	My_exception() { cout << "My_exception()...\n"; }
	~My_exception() { cout << "~My_exception()...\n"; }
};

int main()
{
	try
	{
		My_exception *ptr = new My_exception;
		throw ptr;
	}
	catch(My_exception*)
	{
		cout << "inside catch...\n";
	}
}