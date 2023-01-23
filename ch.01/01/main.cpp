#include <iostream>
#include <cerrno>
#include <csignal>
using namespace std;

int get_error_code()
{
	return 42;
}

void set_errno()
{
	errno = 2;
}

void signal_func()
{
	cout << "inside signal_func()...\n";
	raise(SIGABRT);
}

void except_func()
{
	cout << "inside except_func()...\n";
	throw 'c';
}

int main()
{
	cout << "error_code = " << get_error_code() << endl;

    set_errno();
	cout << "errno = "      << errno << endl;

	///signal_func();
	///cout << "after call signal_func()...\n";
	try
	{
		cout << "inside try...\n";
		except_func();
	}
	catch (...)
	{
		cout << "inside catch...\n";
	}

	cout << "after catch...\n";
}