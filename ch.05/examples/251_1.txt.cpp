//: C05:OurMin2.h
// Объявление min как экспортированного шаблона
// (работает только в компиляторах на базе EDG)
#ifndef OURMIN2_H
#define OURMIN2_H
// Объявление min
export template<typename T> const T& min(const T&, const T&);
#endif ///:~ OURMIN2_H ///:~