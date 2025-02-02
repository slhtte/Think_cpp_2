//: C07:UniqueList.cpp
// ������������ ������� unique() ���������� list
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int a[] = { 1, 3, 1, 4, 1, 5, 1, 6, 1 };
const int asz = sizeof a / sizeof *a;

int main() {
  // ��� ������:
  ostream_iterator<int> out(cout, " ");
  list<int> li(a, a + asz);
  li.unique();
  // ������! ��������� �������� � ����������:
  copy(li.begin(), li.end(), out);
  cout << endl;
  // ������ ���������� �������������� �������������:
  li.sort();
  copy(li.begin(), li.end(), out);
  cout << endl;
  // ������ ������� unique() �������� ���������:
  li.unique();
  copy(li.begin(), li.end(), out);
  cout << endl;
} ///:~