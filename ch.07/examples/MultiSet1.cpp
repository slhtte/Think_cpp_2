//: C07:MultiSet1.cpp
// ���������������
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class X {
  char c; // ������������ ��� ���������
  int i; // �� ������������ ��� ���������
  // ����������� �� ��������� � �������� = �� �����
  X();
  X& operator=(const X&);
  // ������ ����� ���������� ����������� (�� � ������ ������
  // �������� � ��������������� ������)
public:
  X(char cc, int ii) : c(cc), i(ii) {}
  // �������� ��������: �������� == ����� �������������
  friend bool operator<(const X& x, const X& y) {
    return x.c < y.c;
  }
  friend ostream& operator<<(ostream& os, X x) {
    return os << x.c << ":" << x.i;
  }
};

class Xgen {
  static int i;
  // ���������� ��������� ��������:
  enum { span = 6 };
public:
  X operator()() {
    char c = 'A' + rand() % span;
    return X(c, i++);
  }
};

int Xgen::i = 0;

typedef multiset<X> Xmset;
typedef Xmset::const_iterator Xmit;

int main() {
  Xmset mset;
  // ���������� ��������� X:
  srand(time(0));   // ��������� ���������� ��������� �����
  generate_n(inserter(mset, mset.begin()),
    25, Xgen());
  // ������������� �������� ��������� �� ���� mset:
  set<X> unique(mset.begin(), mset.end());
  copy(unique.begin(), unique.end(),
    ostream_iterator<X>(cout, " "));
  cout << "\n----\n";
  // ������� ���������� ��������:
  for(set<X>::iterator i = unique.begin();
      i != unique.end(); i++) {
    pair<Xmit, Xmit> p = mset.equal_range(*i);
    copy(p.first, p.second,
      ostream_iterator<X>(cout, " "));
    cout << endl;
  }
} ///:~