//: C07:VectorCoreDump.cpp
// Появление недействительных итераторов
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vi(10, 0);
  ostream_iterator<int> out(cout, " ");
  vector<int>::iterator i = vi.begin();
  *i = 47;
  copy(vi.begin(), vi.end(), out);
  cout << endl;
  // Выполняем принудительное перераспределение памяти
  // (также можно было бы добавить нужное количество объектов):
  vi.resize(vi.capacity() + 1);
  // Теперь i ссылается на недействительную память:
  *i = 48;  // Нарушение доступа
  copy(vi.begin(), vi.end(), out); // vi[0] не изменяется
} ///:~