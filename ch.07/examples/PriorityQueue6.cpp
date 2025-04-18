//: C07:PriorityQueue6.cpp
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

template<class T, class Compare>
class PQV : public vector<T> {
  Compare comp;
  bool sorted;
  void assureHeap() {
    if(sorted) {
      // �������� �������������� ������ � ����:
      make_heap(this->begin(), this->end(), comp);
      sorted = false;
    }
  }
public:
  PQV(Compare cmp = Compare()) : comp(cmp) {
    make_heap(this->begin(), this->end(), comp);
    sorted = false;
  }
  const T& top() {
    assureHeap();
    return this->front();
  }
  void push(const T& x) {
    assureHeap();
    this->push_back(x);  // ������� ������� � �����
    // ������ ��������� � ����:
    push_heap(this->begin(), this->end(), comp);
  }
  void pop() {
    assureHeap();
    // ����������� �������� �������� � ��������� �������:
    pop_heap(this->begin(), this->end(), comp);
    // �������� ��������:
    this->pop_back();
  }
  void sort() {
    if(!sorted) {
      sort_heap(this->begin(), this->end(), comp);
      reverse(this->begin(), this->end());
      sorted = true;
    }
  }
};

int main() {
  PQV<int, less<int> > pqi;
  srand(time(0));
  for(int i = 0; i < 100; i++) {
    pqi.push(rand() % 25);
    copy(pqi.begin(), pqi.end(),
      ostream_iterator<int>(cout, " "));
    cout << "\n-----\n";
  }
  pqi.sort();
  copy(pqi.begin(), pqi.end(),
    ostream_iterator<int>(cout, " "));
  cout << "\n-----\n";
  while(!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();
  }
} ///:~