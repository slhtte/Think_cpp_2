//: C13:PStash.h
// Вместо объектов в контейнере хранятся указатели
#ifndef PSTASH_H
#define PSTASH_H

#include <stdexcept>

class PStash {
  int quantity; // Количество элементов
  int next; // Следующий пустой элемент
   // Память для хранения указателей:
  void** storage;
  void inflate(int increase);
public:
  PStash() : quantity(0), storage(0), next(0) {}
  ~PStash();
  int add(void* element);
  void* operator[](int index) const throw (std::out_of_range); // Выборка
  // Удаление ссылки из PStash:
  void* remove(int index);
  // Количество элементов в Stash:
  int count() const { return next; }
};
#endif // PSTASH_H ///:~