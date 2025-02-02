#include <iostream>

template<typename T> T f(T t)
{
	std::cout << "base template\n";
	return t;
}

template<> int f(int t)
{
	std::cout << "fool spec\n";
	return t;
}

int f (int t)
{
	std::cout << "non template\n";
	return t;
}

int main()
{
	char c = f('c');
	int j = f(1);
	j = f<>(1);
}