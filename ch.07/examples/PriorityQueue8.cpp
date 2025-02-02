//: C07:PriorityQueue8.cpp
// Более компактная версия PriorityQueue7.cpp
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

template<class T> class PQV : public priority_queue<T> {
public:
  typedef vector<T> TVec;
  TVec get_vector() {
    TVec r(priority_queue<T>::c.begin(), priority_queue<T>::c.end());
    // Базовая куча хранится в переменной c
    sort_heap(r.begin(), r.end(), priority_queue<T>::comp);
    // Приведение к порядку приоритетной очереди:
    reverse(r.begin(), r.end());
    return r;
  }
};

int main() {
  PQV<int> pqi;
  srand(time(0));
  for(int i = 0; i < 100; i++)
    pqi.push(rand() % 25);
  const vector<int>& v = pqi.get_vector();
  copy(v.begin(), v.end(),
    ostream_iterator<int>(cout, " "));
  cout << "\n-----------\n";
  while(!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();
  }
} ///:~