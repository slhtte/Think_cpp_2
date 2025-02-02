//: C07:MultiSet1.cpp
// Мультимножества
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class X {
  char c; // Используется при сравнении
  int i; // Не используется при сравнении
  // Конструктор по умолчанию и оператор = не нужны
  X();
  X& operator=(const X&);
  // Обычно нужен копирующий конструктор (но в данном случае
  // подойдет и сгенерированная версия)
public:
  X(char cc, int ii) : c(cc), i(ii) {}
  // Обратите внимание: оператор == может отсутствовать
  friend bool operator<(const X& x, const X& y) {
    return x.c < y.c;
  }
  friend ostream& operator<<(ostream& os, X x) {
    return os << x.c << ":" << x.i;
  }
};

class Xgen {
  static int i;
  // Количество возможных символов:
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
  // Заполнение объектами X:
  srand(time(0));   // Раскрутка генератора случайных чисел
  generate_n(inserter(mset, mset.begin()),
    25, Xgen());
  // Инициализация обычного множества на базе mset:
  set<X> unique(mset.begin(), mset.end());
  copy(unique.begin(), unique.end(),
    ostream_iterator<X>(cout, " "));
  cout << "\n----\n";
  // Перебор уникальных значений:
  for(set<X>::iterator i = unique.begin();
      i != unique.end(); i++) {
    pair<Xmit, Xmit> p = mset.equal_range(*i);
    copy(p.first, p.second,
      ostream_iterator<X>(cout, " "));
    cout << endl;
  }
} ///:~