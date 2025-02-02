//: C05:Urand.h {-bor}
// ��������� ���������� ��������� �����
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
  Urand() { srand(time(0)); } // ���������
  size_t operator()(); // �������-��������� 
};

template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
  if(used.count() == UpperBound)
    used.reset();  // ����� (������� ������� bitset)
  size_t newval;
  while(used[newval = rand() % UpperBound])
    ; // ���� �� ����� ������� ���������� ��������
  used[newval] = true;
  return newval;
}
#endif // URAND_H ///:~