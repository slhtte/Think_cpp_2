//: C05:FriendScope.cpp
#include <iostream>
using namespace std;

class Friendly {
  int i;
public:
  Friendly(int theInt) { i = theInt; }
  friend void f(const Friendly&); // Необходимо глобальное определение
  void g() { f(*this); }
};

void h() {
  f(Friendly(1));  // Использует ADL
}

void f(const Friendly& fo) {  // Определение дружественной функции
  cout << fo.i << endl;
}

int main() {
  h();              // Выводит 1
  Friendly(2).g();  // Выводит 2
} ///:~