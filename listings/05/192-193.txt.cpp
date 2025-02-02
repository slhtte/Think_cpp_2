//: C05:PrintSeq.cpp {-msc}{-mwcc}
// Функция вывода стандартных последовательных контейнеров C++
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
  // Вывод содержимого вектора
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  printSeq(v);
  // Вывод содержимого списка
  list<int> lst;
  lst.push_back(3);
  lst.push_back(4);
  printSeq(lst);
} ///:~