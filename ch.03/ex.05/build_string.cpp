#include <string>
#include <iostream>
using namespace std;

int main()
{
	string one("I walked down the canyon with the moving mountain bikers.");
	string two("The bikers passed by me too close for comfort.");
	string three("I went hiking instead.");

	string result;

	string walk(one, one.find('w'), one.find('k') + 1 - one.find('w'));
	string mov(one, one.find('m'), one.find('v') - one.find('m') + 1);
	one.replace(one.find('m'), one.find('g') - one.find('m') + 2, result);

	one.replace(one.find('w'), walk.size(), mov);

	string mountain(one, one.rfind('m'), one.rfind('n') - one.rfind('m') + 2);

	two.insert(two.find('e') + 2, mountain);

	three.insert(three.begin(), 'S');
	three.insert(three.begin() + 1, 'o');
	three.insert(three.begin() + 2, ' ');

	result = one + ' ' + two + ' ' + three;

	//I moved down the canyon with the mountain bikers.
	//The mountain bikers passed by me too close for comfort.
	//So I went hiking instead.

	cout << result << endl;

	return 0;
}