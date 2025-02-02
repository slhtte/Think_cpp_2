//: C05:PartialOrder2.cpp
// Неполные приоритеты при выборе шаблона класса
#include <iostream>
using namespace std;

template<class T, class U> class C {
public:
  void f() { cout << "Primary Template\n"; }
};

template<class U> class C<int, U> {
public:
  void f() { cout << "T == int\n"; }
};

template<class T> class C<T, double> {
public:
  void f() { cout << "U == double\n"; }
};

template<class T, class U> class C<T*, U> {
public:
  void f() { cout << "T* used \n"; }
};

template<class T, class U> class C<T, U*> {
public:
  void f() { cout << "U* used\n"; }
};

template<class T, class U> class C<T*, U*> {
public:
  void f() { cout << "T* and U* used\n"; }
};

template<class T> class C<T, T> {
public:
  void f() { cout << "T == U\n"; }
};

int main() {
  C<float, int>().f();    // 1: Основной шаблон
  C<int, float>().f();    // 2: T == int
  C<float, double>().f(); // 3: U == double
  C<float, float>().f();  // 4: T == U
  C<float*, float>().f(); // 5: Используется T* [float]
  C<float, float*>().f(); // 6: Используется U* [float]
  C<float*, int*>().f();  // 7: Используются T* и U* [float,int]

  // Следующие вызовы неоднозначны:
//   8: C<int, int>().f();
//   9: C<double, double>().f();
//  10: C<float*, float*>().f();
//  11: C<int, int*>().f();
//  12: C<int*, int*>().f();
} ///:~