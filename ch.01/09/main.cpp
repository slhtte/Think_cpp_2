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
		case 4: throw My_exception();
		default: return;
	}
}

int main()
{
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
		catch(exception&)
		{
			cout << "inside catch(My_exception)\n";
			quit = true;
		}
	}

	cout << "before exit()...\n";
}

