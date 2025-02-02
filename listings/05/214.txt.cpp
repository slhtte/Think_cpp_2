//: C05:DelayedInstantiation.cpp
// Генерируется только код используемых функций шаблонов классов.

class X {
public:
  void f() {}
};

class Y {
public:
  void g() {}
};

template <typename T> class Z {
  T t;
public:
  void a() { t.f(); }
  void b() { t.g(); }
};

int main() {
  Z<X> zx;
  zx.a(); // Код Z<X>::b() не генерируется
  Z<Y> zy;
  zy.b(); // Код Z<Y>::a() не генерируется
} ///:~