//: C07:NoisyMap.cpp
// Отображение Noisy в Noisy
//{L} Noisy
#include <map>
#include "Noisy.h"
using namespace std;

int main() {
  map<Noisy, Noisy> mnn;
  Noisy n1, n2;
  cout << "\n--------\n";
  mnn[n1] = n2;
  cout << "\n--------\n";
  cout << mnn[n1] << endl;
  cout << "\n--------\n";
} ///:~