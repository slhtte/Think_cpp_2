//: C05:Accumulate.cpp
// Передача "функции" как параметра на стадии компиляции
#include <iostream>
using namespace std;

// Накопление результатов F(0)..F(n)
template<int n, template<int> class F> struct Accumulate {
   enum {val = Accumulate<n-1, F>::val + F<n>::val};
};

// Критерий остановки (возвращает значение F(0))
template<template<int> class F> struct Accumulate<0, F> {
   enum {val = F<0>::val};
};

// Различные "функции":
template<int n> struct Identity {
   enum {val = n};
};

template<int n> struct Square {
   enum {val = n*n};
};

template<int n> struct Cube {
   enum {val = n*n*n};
};

int main() {
   cout << Accumulate<4, Identity>::val << endl; // 10
   cout << Accumulate<4, Square>::val << endl;   // 30
   cout << Accumulate<4, Cube>::val << endl;     // 100
} ///:~