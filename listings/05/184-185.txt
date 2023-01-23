//: C05:Urand.h {-bor}
// Генератор уникальных случайных чисел
#ifndef URAND_H
#define URAND_H
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using std::size_t;
using std::bitset;

template<size_t UpperBound>
class Urand {
  bitset<UpperBound> used;
public:
  Urand() { srand(time(0)); } // Раскрутка
  size_t operator()(); // Функция-генератор 
};

template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
  if(used.count() == UpperBound)
    used.reset();  // Сброс (очистка объекта bitset)
  size_t newval;
  while(used[newval = rand() % UpperBound])
    ; // Пока не будет найдено уникальное значение
  used[newval] = true;
  return newval;
}
#endif // URAND_H ///:~