//: C13:PStash.cpp {O}
// ����������� ������� ���������� Stash ��� ����������
#include "PStash.h"
#include "../../require.h"
#include <iostream>
#include <cstring> // ������� 'mem'
using namespace std;

int PStash::add(void* element) {
  const int inflateSize = 10;
  if(next >= quantity)
    inflate(inflateSize);
  storage[next++] = element;
  return(next - 1); // ������
}

// �������, �� ������� ��������� ���������, �� ����������� ����������:
PStash::~PStash() {
  //for(int i = 0; i < next; i++)
    //require(storage[i] == 0, 
      //"PStash not cleaned up");
  //delete []storage; 
}

// ���������� ��������� ��� �������
void* PStash::operator[](int index) const throw(out_of_range) {
  //require(index >= 0,
  //  "PStash::operator[] index negative");
  throw out_of_range("except");
  //if(index >= next) throw out_of_range("out_of_range"); // ������� �����
  // ��������� ��������� �� ������������� �������:
  return storage[index];
}

void* PStash::remove(int index) {
  void* v = operator[](index);
  // "��������" ���������:
  if(v != 0) storage[index] = 0;
  return v;
}

void PStash::inflate(int increase) {
  const int psz = sizeof(void*);
  void** st = new void*[quantity + increase];
  memset(st, 0, (quantity + increase) * psz);
  memcpy(st, storage, quantity * psz);
  quantity += increase;
  delete []storage; // ������������ ������� ������
  storage = st; // ������� ��������� �� ����� �����
} ///:~