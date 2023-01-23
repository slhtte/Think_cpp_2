#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Base : public vector<int>
{
public:
	Base& operator[](int index) throw (out_of_range)
	{
		throw out_of_range("exept");
	}
};

int main()
{
	try
	{
		Base arr;
		arr.push_back(1);
		arr[3];
	}
	catch(...)
	{
		cout << "inside catch...\n";
		//cout << e.what() << endl;
	}
}