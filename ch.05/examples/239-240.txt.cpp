//: C05:Conditionals.cpp
// Применение условий стадии компиляции для выбора кода
#include <iostream>
using namespace std;

template<bool cond> struct Select {};

template<> struct Select<true> {
  static inline void statement1() {
    cout << "This is statement1 executing\n";
  }
public:
  static inline void f() { statement1(); }
};

template<> struct Select<false> {
  static inline void statement2() {
    cout << "This is statement2 executing\n";
  }
public:
  static inline void f() { statement2(); }
};

template<bool cond> void execute() {
  Select<cond>::f();
}

int main() {
  execute<sizeof(int) == 4>();
} ///:~
Эта программа эквивалентна следующему выражению:
if(cond)
  statement1();
else
  statement2();