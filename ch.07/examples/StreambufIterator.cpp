//: C07:StreambufIterator.cpp
// istreambuf_iterator � ostreambuf_iterator
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include "../../require.h"
using namespace std;

int main() {
  ifstream in("StreambufIterator.cpp");
  assure(in, "StreambufIterator.cpp");
  // ������ ������������� ������:
  istreambuf_iterator<char> isb(in), end;
  ostreambuf_iterator<char> osb(cout);
  while(isb != end)
    *osb++ = *isb++; // ����������� 'in' � cout
  cout << endl;
  ifstream in2("StreambufIterator.cpp");
  // �������� ���������:
  istream_iterator<char> is(in2), end2;
  ostream_iterator<char> os(cout);
  while(is != end2)
    *os++ = *is++;
  cout << endl;
} ///:~