#include <iostream>
using namespace std;

class Garage
{
public:
	class Car
	{
	public:
		class Motor 
		{
		public:
			Motor()
			{
				cout << "inside Motor()\n";
				throw 1;
			}
		} motor;
		Car() : motor()
		{
			cout << "inside Car()\n";
		}
	} car;

	Garage()
	try
	  : car()
	{
		cout << "inside Garage()...try...\n";
	}
	catch(int&)
	{
		cout << "inside Garage()...catch()...\n";
		throw 'a';
	}
};

int main()
{
	try
	{
		Garage garage;
	}
	catch(char&)
	{
		cout << "inside main()...catch...\n";
	}

	cout << "before exit\n";
}