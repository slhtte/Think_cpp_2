//: C05:OurMin.h
#ifndef OURMIN_H
#define OURMIN_H
// Объявление min()
template<typename T> const T& min(const T&, const T&);
#endif ///:~ OURMIN.Y ///:~

//: C05:OurMin.cpp
#include "OurMin.h"
//Определение min()
template<typename T> const T& min(const T& a, const T& b) {
  return (a < b) ? a : b;
}

//: C05:UseMin1.cpp {O}
#include <iostream>
#include "OurMin.h"
void usemin1() {
  std::cout << min(1,2) << std::endl;
} ///:~

//: C05:UseMin2.cpp {O}
#include <iostream>
#include "OurMin.h"
void usemin2() {
  std::cout << min(3.1,4.2) << std::endl;
} ///:~

//: C05:MinMain.cpp
//{L} UseMin1 UseMin2 MinInstances
void usemin1();
void usemin2();

int main() {
  usemin1();
  usemin2();
} ///:~