//: C07:Ring.cpp
// ���������� ��������� ��������� ������ �� ���� STL
#include <iostream>
#include <iterator>
#include <list>
#include <deque>
#include <vector>
#include <string>
using namespace std;

template
//<class T, template <class U> class C = list > 
<class T, template<class > class C = list >
class Ring {
  C<T> lst;
public:
  // ���������� ������ ���������� ��� ����, �����
  // ��������� ���������� 'friend' ������ �������� 'iterator'
  // ������ std::iterator:
  class iterator;
  friend class iterator;
  class iterator : public std::iterator<
    std::bidirectional_iterator_tag,T,ptrdiff_t>{
    typename C<T>::iterator it;
    C<T>* r;
  public:
    iterator(C<T>& lst,
      const typename C<T>::iterator& i)
      : r(&lst), it(i) {}
    bool operator==(const iterator& x) const {
      return it == x.it;
    }
    bool operator!=(const iterator& x) const {
      return !(*this == x);
    }
    typename C<T>::reference operator*() const {
      return *it;
    }
    iterator& operator++() {
      ++it;
      if(it == r->end())
        it = r->begin();
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      ++*this;
      return tmp;
    }
    iterator& operator--() {
      if(it == r->begin())
        it = r->end();
      --it;
      return *this;
    }
    iterator operator--(int) {
      iterator tmp = *this;
      --*this;
      return tmp;
    }
    iterator insert(const T& x){
      return iterator(*r, r->insert(it, x));
    }
    iterator erase() {
      return iterator(*r, r->erase(it));
    }
  };
  void push_back(const T& x) { lst.push_back(x); }
  iterator begin() { return iterator(lst, lst.begin()); }
  int size() { return lst.size(); }
};

int main() {
  //using Cont = deque;
  Ring<string, deque> rs;
  rs.push_back("one");
  rs.push_back("two");
  rs.push_back("three");
  rs.push_back("four");
  rs.push_back("five");
  Ring<string, deque>::iterator it = rs.begin();
  ++it; ++it;
  it.insert("six");
  it = rs.begin();
  // ���������� ������� ��������� ������:
  for(int i = 0; i < rs.size() * 2; i++)
    cout << *it++ << endl;
} ///:~