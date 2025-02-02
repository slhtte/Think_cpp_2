//: C07:WordCount.cpp
// Подсчет вхождений слов в файле
// с использованием отображения.
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "../../require.h"
using namespace std;

int main(int argc, char* argv[]) {
  typedef map<string, int> WordMap;
  typedef WordMap::iterator WMIter;
  const char* fname = "WordCount.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  WordMap wordmap;
  string word;
  while(in >> word)
    wordmap[word]++;
  for(WMIter w = wordmap.begin(); w != wordmap.end(); w++)
    cout << w->first << ": " << w->second << endl;
} ///:~