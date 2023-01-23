#include <iostream>
#include <stdexcept>
using namespace std;

class My_exception : public exception {};

void func(int arg) throw(char, int, bool, My_exception)
{
	switch (arg)
	{
		case 1: throw 'a';
		case 2: throw 1;
		case 3: throw true;
		case 4: throw 1.1;
		case 5: throw My_exception();
		default: return;
	}
}

void my_unexpected()
{
	cout << "inside my_unexpected()\n";
	throw My_exception();
}

int main()
{
	set_unexpected(my_unexpected);
	bool quit = false;
	int arg = 0;
	while (!quit)
	{
		try
		{
			func(++arg);
		}
		catch(char&)
		{
			cout << "inside catch(char)\n";
		}
		catch(int&)
		{
			cout << "inside catch(int)\n";
		}
		catch(bool&)
		{
			cout << "inside catch(bool)\n";
		}
		/*
		catch(exception&)
		{
			cout << "inside catch(exception&)\n";
		}
		*/
		catch(...)
		{
			cout << "inside catch(...)\n";
			quit = true;
		}
	}

	cout << "before exit()...\n";
}

