//: C07:DequeOverflow.cpp {-bor}
// При включении большого количества элементов
// с конца контейнера дек работает гораздо
// эффективнее вектора, поскольку он не требует
// копирования и уничтожения элементов.
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