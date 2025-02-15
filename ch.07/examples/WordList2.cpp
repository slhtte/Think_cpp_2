//: C07:WordList2.cpp
// istreambuf_iterator � ��������� �������
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../../require.h"
using namespace std;

int main(int argc, char* argv[]) {
  char* fname = "WordList2.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  istreambuf_iterator<char> p(in), end;
  set<string> wordlist;
  while (p != end) {
    string word;
    insert_iterator<string>
      ii(word, word.begin());
    // ����� ������� ����������� �������:
    while (p != end && !isalpha (*p))
      ++p;
    // ����������� �� ������� ������������� �������:
    while (p != end && isalpha (*p))
      ++*ii = *p++;
    if (word.size() != 0)
      wordlist.insert(word);
  }
  // ����� �����������:
  copy(wordlist.begin(), wordlist.end(),
    ostream_iterator<string>(cout, "\n"));
} ///:~