#include <iostream>
using namespace std;

class My
{
	static char *ptr;
public:
	class My_exception {};
	void* operator new[](size_t size) throw(My_exception)
	{
	
		if (size <= 10)
		{
			ptr = ::new char[size];
			cout << "new without exception\n";
		}
		else
		{
			ptr = ::new char[10];
			cout << "new with exception\n";
			throw My_exception();
		}

		return ptr;
	}

	static void cleanup_mem()
	{
		cout << "cleanup_mem()\n";
		::delete []ptr;
	}
};

char* My::ptr = nullptr;

int main()
{
	bool quit = false;
	size_t size = 11;

	while (!quit)
	{
		try
		{
			My *my = new My[size];
			quit = true;
		}
		catch(My::My_exception&)
		{
			cout << "inside catch...\n";
			My::cleanup_mem();
			size = 10;
		}
	}

	cout << "quit after while...\n";
}