//: C07:DequeOverflow.cpp {-bor}
// ��� ��������� �������� ���������� ���������
// � ����� ���������� ��� �������� �������
// ����������� �������, ��������� �� �� �������
// ����������� � ����������� ���������.
#include <cstdlib>
#include <deque>
#include "Noisy.h"
using namespace std;

int main(int argc, char* argv[]) {
  int size = 1000;
  if(argc >= 2) size = atoi(argv[1]);
  deque<Noisy> dn;
  Noisy n;
  for(int i = 0; i < size; i++)
    dn.push_back(n);
  cout << "\n cleaning up " << endl;
} ///:~