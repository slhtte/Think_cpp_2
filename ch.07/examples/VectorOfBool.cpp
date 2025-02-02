//: C07:VectorOfBool.cpp
// ������������� vector<bool>
#include <bitset>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  vector<bool> vb(10, true);
  vector<bool>::iterator it;
  for(it = vb.begin(); it != vb.end(); it++)
    cout << *it;
  cout << endl;
  vb.push_back(false);
  ostream_iterator<bool> out(cout, "");
  copy(vb.begin(), vb.end(), out);
  cout << endl;
  bool ab[] = { true, false, false, true, true,
    true, true, false, false, true };
  // ���������� ������� �����������:
  vb.assign(ab, ab + sizeof(ab)/sizeof(bool));
  copy(vb.begin(), vb.end(), out);
  cout << endl;
  vb.flip(); // �������������� ���� �����
  copy(vb.begin(), vb.end(), out);
  cout << endl;
  for(size_t i = 0; i < vb.size(); i++)
    vb[i] = 0; // (���������� "false")
  vb[4] = true;
  vb[5] = 1;
  vb[7].flip(); // �������������� ������ ����
  copy(vb.begin(), vb.end(), out);
  cout << endl;
  // �������������� � bitset:
  ostringstream os;
  copy(vb.begin(), vb.end(),
    ostream_iterator<bool>(os, ""));
  bitset<10> bs(os.str());
  cout << "Bitset:\n" << bs << endl;
} ///:~