//: C07:VectorOverflow.cpp {-bor}
// Демонстрация конструирования копий и уничтожения объектов
// при перераспределении памяти вектора
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Noisy.h"
using namespace std;

int main(int argc, char* argv[]) {
  int size = 1000;
  if(argc >= 2) size = atoi(argv[1]);
  vector<Noisy> vn;
  vn.reserve(size);
  Noisy n;
  for(int i = 0; i < size; i++)
    vn.push_back(n);
  cout << "\n cleaning up " << endl;
} ///:~