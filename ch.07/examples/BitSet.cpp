//: C07:BitSet.cpp {-bor}
// ������ � ������� bitset
#include <bitset>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

const int SZ = 32;
typedef bitset<SZ> BS;

template<int bits> bitset<bits> randBitset() {
  bitset<bits> r(rand());
  for(int i = 0; i < bits/16 - 1; i++) {
    r <<= 16;
    // ����������� ��������� "OR" � �������� 16 ������
    // ������ ��������:
    r |= bitset<bits>(rand());
  }
  return r;
}

int main() {
  srand(time(0));
  cout << "sizeof(bitset<16>) = "
    << sizeof(bitset<16>) << endl;
  cout << "sizeof(bitset<32>) = "
    << sizeof(bitset<32>) << endl;
  cout << "sizeof(bitset<48>) = "
    << sizeof(bitset<48>) << endl;
  cout << "sizeof(bitset<64>) = "
    << sizeof(bitset<64>) << endl;
  cout << "sizeof(bitset<65>) = "
    << sizeof(bitset<65>) << endl;
  BS a(randBitset<SZ>()), b(randBitset<SZ>());
  // �������������� �������� ���� � �����:
  unsigned long ul = a.to_ulong();
  cout << ul << endl;
  // �������������� ������ � ������� ����:
  string cbits("111011010110111");
  cout << "as a string = " << cbits <<endl;
  cout << BS(cbits) << " [BS(cbits)]" << endl;
  cout << BS(cbits, 2)
    << " [BS(cbits, 2)]" << endl;
  cout << BS(cbits, 2, 11)
    << " [BS(cbits, 2, 11)]" << endl;
  cout << a << " [a]" << endl;
  cout << b << " [b]" << endl;
  // ����������� �������� AND:
  cout << (a & b) << " [a & b]" << endl;
  cout << (BS(a) &= b) << " [a &= b]" << endl;
  // ����������� �������� OR:
  cout << (a | b) << " [a | b]" << endl;
  cout << (BS(a) |= b) << " [a |= b]" << endl;
  // ����������� �������� ������������ OR:
  cout << (a ^ b) << " [a ^ b]" << endl;
  cout << (BS(a) ^= b) << " [a ^= b]" << endl;
  cout << a << " [a]" << endl; // ��� ���������
  // ���������� ����� ����� (� ����������� ������):
  cout << (BS(a) <<= SZ/2)
    << " [a <<= (SZ/2)]" << endl;
  cout << (a << SZ/2) << endl;
  cout << a << " [a]" << endl; // ��� ���������
  // ���������� ����� ������ (� ����������� ������):
  cout << (BS(a) >>= SZ/2)
    << " [a >>= (SZ/2)]" << endl;
  cout << (a >> SZ/2) << endl;
  cout << a << " [a]" << endl; // ��� ���������
  cout << BS(a).set() << " [a.set()]" << endl;
  for(int i = 0; i < SZ; i++)
    if(!a.test(i)) {
      cout << BS(a).set(i)
        << " [a.set(" << i <<")]" << endl;
      break; // ������ ���� ��������
    }
  cout << BS(a).reset() << " [a.reset()]"<< endl;
  for(int j = 0; j < SZ; j++)
    if(a.test(j)) {
      cout << BS(a).reset(j)
        << " [a.reset(" << j <<")]" << endl;
      break; // ������ ���� ��������
    }
  cout << BS(a).flip() << " [a.flip()]" << endl;
  cout << ~a << " [~a]" << endl;
  cout << a << " [a]" << endl; // ��� ���������
  cout << BS(a).flip(1) << " [a.flip(1)]"<< endl;
  BS c;
  cout << c << " [c]" << endl;
  cout << "c.count() = " << c.count() << endl;
  cout << "c.any() = "
    << (c.any() ? "true" : "false") << endl;
  cout << "c.none() = "
    << (c.none() ? "true" : "false") << endl;
  c[1].flip(); c[2].flip();
  cout << c << " [c]" << endl;
  cout << "c.count() = " << c.count() << endl;
  cout << "c.any() = "
    << (c.any() ? "true" : "false") << endl;
  cout << "c.none() = "
    << (c.none() ? "true" : "false") << endl;
  // ����������:
  c.reset();
  for(int k = 0; k < c.size(); k++)
    if(k % 2 == 0)
      c[k].flip();
  cout << c << " [c]" << endl;
  c.reset();
  // ������������ ���������� ��������:
  for(int ii = 0; ii < c.size(); ii++)
    c[ii] = (rand() % 100) < 25;
  cout << c << " [c]" << endl;
  // �������� ���������� ��������:
  if(c[1])
    cout << "c[1] == true";
  else
    cout << "c[1] == false" << endl;
} ///:~