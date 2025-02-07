//: C07:AssocInserter.cpp
// �������� ������� ������ ���������
// ������������� ���������� fill_n() � generate_n()
// � �������������� ������������.
#include <iterator>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "SimpleGenerators.h"
using namespace std;

int main() {
  set<int> s;
  cout << s.size() << " "<< &(*s.begin()) << endl;
  fill_n(inserter(s, s.begin()), 10, 47);
  cout << s.size() << " "<< &(*s.begin()) << endl;
  generate_n(inserter(s, s.begin()), 10,
    IncrGen<int>(12));
  cout << s.size() << endl;
  copy(s.begin(), s.end(),
    ostream_iterator<int>(cout, "\n"));
  map<int, int> m;
  fill_n(inserter(m, m.begin()), 10, make_pair(90,120));
  generate_n(inserter(m, m.begin()), 10,
    PairGen<int, int>(3, 9));
  copy(m.begin(), m.end(),
    ostream_iterator<pair<int,int> >(cout,"\n"));
} ///:~