//: C13:PStash.cpp {O}
// Определения функций контейнера Stash для указателей
#include "PStash.h"
#include "../../require.h"
#include <iostream>
#include <cstring> // Функции 'mem'
using namespace std;

int PStash::add(void* element) {
  const int inflateSize = 10;
  if(next >= quantity)
    inflate(inflateSize);
  storage[next++] = element;
  return(next - 1); // Индекс
}

// Объекты, на которые ссылаются указатели, не принадлежат контейнеру:
PStash::~PStash() {
  //for(int i = 0; i < next; i++)
    //require(storage[i] == 0, 
      //"PStash not cleaned up");
  //delete []storage; 
}

// Перегрузка оператора для выборки
void* PStash::operator[](int index) const throw(out_of_range) {
  //require(index >= 0,
  //  "PStash::operator[] index negative");
  throw out_of_range("except");
  //if(index >= next) throw out_of_range("out_of_range"); // Признак конца
  // Получение указателя на запрашиваемый элемент:
  return storage[index];
}

void* PStash::remove(int index) {
  void* v = operator[](index);
  // "Удаление" указателя:
  if(v != 0) storage[index] = 0;
  return v;
}

void PStash::inflate(int increase) {
  const int psz = sizeof(void*);
  void** st = new void*[quantity + increase];
  memset(st, 0, (quantity + increase) * psz);
  memcpy(st, storage, quantity * psz);
  quantity += increase;
  delete []storage; // Освобождение старого буфера
  storage = st; // Перевод указателя на новый буфер
} ///:~