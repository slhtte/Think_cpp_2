//: C07:WordList.cpp
// Вывод списка слов, встречающихся в документе
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include "../../require.h"
using namespace std;

char replaceJunk(char c) {
   // В тексте остаются только алфавитные символы,
   // пробелы (в качестве разделителей) и символы '
   return (isalpha(c) || c == '\'') ? c : ' ';
}
int main(int argc, char* argv[]) {
  char* fname = "WordList.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  set<string> wordlist;
  string line;
  while(getline(in, line)) {
    transform(line.begin(), line.end(), line.begin(), replaceJunk);
    istringstream is(line);
    string word;
    while (is >> word)
      wordlist.insert(word);
    }
  // Вывод результатов:
  copy(wordlist.begin(), wordlist.end(),
       ostream_iterator<string>(cout, "\n"));
} ///:~