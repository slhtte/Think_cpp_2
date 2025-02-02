#include <iostream>

template <class R>
void func(int i, int *p, int *sp, R (*fp)())
{
	using std::cout;
	using std::endl;

	cout << i << endl;
	cout << p << endl;
	cout << sp << endl;
	cout << *fp << endl;
}

class C
{
public:
	static int i;
	static int func()
	{
		return i;
	}
};

int C::i = 0;

int main()
{
    int i = 1;
    int *p = &C::i;
    int (*fp)() = &C::func;
	func(i, &i, p, fp);
}