#include <iostream>
#include <string>

class my_setw
{
	std::string str;
public:
	my_setw(const std::string &s, int w) :
	    str(s, 0, w) {;}

	friend std::ostream& operator<<(std::ostream &os, const my_setw &ms)
	{
		return os << ms.str;
	}
};

int main()
{

}