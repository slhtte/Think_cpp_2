//: C05:TypenamedID.cpp {-bor}
// typename в качестве префикса вложенных типов

template<class T> class X {
  // Без typename в программе произойдет ошибка:
  typename T::id i;
public:
  void f() { i.g(); }
};

class Y {
public:
  class id {
  public:
    void g() {}
  };
};

int main() {
  X<Y> xy;
  xy.f();
} ///:~