//: C05:TempTemp4.cpp {-bor}{-msc}
// Передача стандартных последовательных контейнеров
// в аргументах шаблонов
#include <iostream>
#include <list>
#include <memory>  // Объявление allocator<T>
#include <vector>
using namespace std;

template<class T, template<class U, class = allocator<U> >
                    class Seq>
class Container {
  Seq<T> seq; // Неявное применение allocator<T>
public:
  void push_back(const T& t) { seq.push_back(t); }
  typename Seq<T>::iterator begin() { return seq.begin(); }
  typename Seq<T>::iterator end() { return seq.end(); }
};

int main() {
  // Передача контейнера vector
  Container<int, vector> vContainer;
  vContainer.push_back(1);
  vContainer.push_back(2);
  for(vector<int>::iterator p = vContainer.begin();
      p != vContainer.end(); ++p) {
    cout << *p << endl;
  }
  // Передача контейнера list
  Container<int, list> lContainer;
  lContainer.push_back(3);
  lContainer.push_back(4);
  for(list<int>::iterator p2 = lContainer.begin();
      p2 != lContainer.end(); ++p2) {
    cout << *p2 << endl;
  }
} ///:~