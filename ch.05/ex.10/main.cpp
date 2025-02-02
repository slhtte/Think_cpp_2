#include <iostream>

template <typename T> class Friendly;
template <typename T> class Picky;

template <typename T>
class Bob
{
	T t;
public:
	template <typename U>
	void func(Friendly<U> &f)
	{
		std::cout << f.t << std::endl;
	}

	template <typename U>
	void func2(Picky<U> &f)
	{
		std::cout << f.t << std::endl;
	}
};

template <typename T>
class Friendly
{
	T t;
public:
	void set(T tt) { t = tt; }
	template <typename R> friend class Bob;
};

template <typename T>
class Picky
{
	T t;
public:
	void set(T tt) { t = tt; }
	friend class Bob<T>;
};

int main()
{
	Friendly<long> f;
	f.set(3);
	Bob<long>().func(f);

	Picky<long> p;
	p.set(4);
	Bob<long>().func2(p);
}