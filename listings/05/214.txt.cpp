//: C05:DelayedInstantiation.cpp
// ������������ ������ ��� ������������ ������� �������� �������.

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
  zx.a(); // ��� Z<X>::b() �� ������������
  Z<Y> zy;
  zy.b(); // ��� Z<Y>::a() �� ������������
} ///:~