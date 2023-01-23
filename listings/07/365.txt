//: C07:UniqueList.cpp
// Тестирование функции unique() контейнера list
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int a[] = { 1, 3, 1, 4, 1, 5, 1, 6, 1 };
const int asz = sizeof a / sizeof *a;

int main() {
  // Для вывода:
  ostream_iterator<int> out(cout, " ");
  list<int> li(a, a + asz);
  li.unique();
  // Ошибка! Дубликаты остаются в контейнере:
  copy(li.begin(), li.end(), out);
  cout << endl;
  // Список необходимо предварительно отсортировать:
  li.sort();
  copy(li.begin(), li.end(), out);
  cout << endl;
  // Теперь функция unique() работает правильно:
  li.unique();
  copy(li.begin(), li.end(), out);
  cout << endl;
} ///:~