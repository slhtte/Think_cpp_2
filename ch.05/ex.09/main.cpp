#include <iostream>

class My1
{
public:
	void func()
	{
		std::cout << "My1::func()\n";
	}
};

class My2
{
public:
	void func()
	{
		std::cout << "My2::func()\n";
	}
};

class My3
{
public:
	void func()
	{
		std::cout << "My3::func()\n";
	}
};

template <class T, class R>
class C
{
	T t;
	R r;
public:
	C(T tt, R rr) : t(tt), r(rr) {}

	void funcT()
	{
		t.func();
	}

	void funcR()
	{
		r.func();
	}

	void print() const
	{
		std::cout << "template<class T, class R> class C\n";
	}
};

template <class R>
class C<My1, R>
{
	My1 t;
	R r;
	int i = 2;
public:
	C(My1 m, R rr, int ii = 0) : t(m), r(rr), i(ii) {}
	void funcT()
	{
		t.func();
	}

	void funcR()
	{
		r.func();
	}

	void print() const
	{
		std::cout << "template<class R> class C <My1, R>\n";
	}	
};


template <class T>
class C<T, My2>
{
	T t;
	My2 r;
	char c;
public:
	C(T tt, My2 rr, char cc = 'c') : t(tt), r(rr), c(cc) {}
	void funcT()
	{
		t.func();
	}

	void funcR()
	{
		r.func();
	}	

    void print() const
	{
		std::cout << "template<class T> class C <T, My2>\n";
	}	
};


int main()
{
	My1 m1;
	My2 m2;
	My3 m3;
//	C<My1,My2> c1 = C<My1, My2>(m1, m2);
//	c1.print();

	C<My1, My3> c2 = C<My1, My3>(m1, m3, 0);
	c2.print();

	C<My3, My2> c3 = C<My3, My2>(m3, m2, 'b');
	c3.print();
}