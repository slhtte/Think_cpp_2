//: C07:RawStorageIterator.cpp {-bor}
// ������������� raw_storage_iterator
//{L} Noisy
#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>
#include "Noisy.h"
using namespace std;

int main() {
  const int quantity = 10;
  // ��������� ������ � ���������� � ������� ����:
  Noisy* np =
    reinterpret_cast<Noisy*>(
      new char[quantity * sizeof(Noisy)]);
  raw_storage_iterator<Noisy*, Noisy> rsi(np);
  for(int i = 0; i < quantity; i++)
    *rsi++ = Noisy(); // ���������� �������� � ������
  cout << endl;
  copy(np, np + quantity,
    ostream_iterator<Noisy>(cout, " "));
  cout << endl;
  // ����� ����� �����������:
  for(int j = 0; j < quantity; j++)
    np[j].~Noisy();
  // ������������ ������:
  delete reinterpret_cast<char*>(np);
} ///:~