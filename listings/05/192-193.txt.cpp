//: C05:PrintSeq.cpp {-msc}{-mwcc}
// ������� ������ ����������� ���������������� ����������� C++
#include <iostream>
#include <list>
#include <memory>
#include <vector>
using namespace std;

template<class T, template<class U, class = allocator<U> >
                  class Seq>
void printSeq(Seq<T>& seq) {
  for (typename Seq<T>::iterator b = seq.begin();
       b != seq.end();)
    cout << *b++ << endl;
}

int main() {
  // ����� ����������� �������
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  printSeq(v);
  // ����� ����������� ������
  list<int> lst;
  lst.push_back(3);
  lst.push_back(4);
  printSeq(lst);
} ///:~