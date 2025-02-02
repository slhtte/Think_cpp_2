// C05:OurMin2.cpp
// Определение экспортированного шаблона min
// (работает только в компиляторах на базе EDG)
#include "OurMin2.h"
export
template<typename T> const T& min(const T& a, const T& b) {
  return (a < b) ? a : b;
} ///:~