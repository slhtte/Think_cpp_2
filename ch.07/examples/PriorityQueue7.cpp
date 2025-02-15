//: C07:PriorityQueue7.cpp
// ������������ �������, ���������
// ��������������� ������ �� �������
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

template<class T, class Compare> class PQV {
  vector<T> v;
  Compare comp;
public:
  // �������� make_heap() �� �����;
  // ��������� �� �������� ���������
  PQV(Compare cmp = Compare()) : comp(cmp) {}
  void push(const T& x) {
    // ������� ������� � �����:
    v.push_back(x);
    // ������ ��������� � ����:
    push_heap(v.begin(), v.end(), comp);
  }
  void pop() {
    // ����������� �������� �������� � ��������� �������:
    pop_heap(v.begin(), v.end(), comp);
    // �������� ��������:
    v.pop_back();
  }
  const T& top() { return v.front(); }
  bool empty() const { return v.empty(); }
  int size() const { return v.size(); }
  typedef vector<T> TVec;
  TVec Vector() {
    TVec r(v.begin(), v.end());
    // �������� ������������� ������������ ����
    sort_heap(r.begin(), r.end(), comp);
    // ���������� � ������� ������������ �������:
    reverse(r.begin(), r.end());
    return r;
  }
};

int main() {
  PQV<int, less<int> > pqi;
  srand(time(0));
  for(int i = 0; i < 100; i++)
    pqi.push(rand() % 25);
  const vector<int>& v = pqi.Vector();
  copy(v.begin(), v.end(),
    ostream_iterator<int>(cout, " "));
  cout << "\n-----------\n";
  while(!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();
  }
} ///:~