//: C07:Valarray1.cpp {-bor}
// ������� ����������� valarray
#include "PrintValarray.h"
using namespace std;

double f(double x) { return 2.0 * x - 1.0; }

int main() {
  double n[] = {1.0, 2.0, 3.0, 4.0};
  valarray<double> v(n, sizeof n / sizeof n[0]);
  print("v", v);
  valarray<double> sh(v.cshift(1));
  print("shift 1", sh);
  valarray<double> acc(v + sh);
  print("sum", acc);
  valarray<double> trig(sin(v) + cos(acc));
  print("trig", trig);
  valarray<double> p(pow(v, 3.0));
  print("3rd power", p);
  valarray<double> app(v.apply(f));
  print("f(v)", app);
  valarray<bool> eq(v == app);
  print("v == app?", eq);
  double x = v.min();
  double y = v.max();
  double z = v.sum();
  cout << "x = " << x << ", y = " << y
    << ", z = " << z  << endl;
} ///:~