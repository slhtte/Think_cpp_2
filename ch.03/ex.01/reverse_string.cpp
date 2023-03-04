#include <string>
#include <cassert>
using namespace std;

string reverse_string(const string& s)
{
	string str{s};

	for (auto i = 0; i <= (str.size() - 1) / 2; ++i)
	{
		swap(str[i], str[str.size() - 1 - i]);
	}

	return str;
}

int main()
{
	assert(reverse_string("hello") == "olleh");
	assert(reverse_string("aabb") == "bbaa");
}