//: C13:PStash.h
// ������ �������� � ���������� �������� ���������
#ifndef PSTASH_H
#define PSTASH_H

#include <stdexcept>

class PStash {
  int quantity; // ���������� ���������
  int next; // ��������� ������ �������
   // ������ ��� �������� ����������:
  void** storage;
  void inflate(int increase);
public:
  PStash() : quantity(0), storage(0), next(0) {}
  ~PStash();
  int add(void* element);
  void* operator[](int index) const throw (std::out_of_range); // �������
  // �������� ������ �� PStash:
  void* remove(int index);
  // ���������� ��������� � Stash:
  int count() const { return next; }
};
#endif // PSTASH_H ///:~