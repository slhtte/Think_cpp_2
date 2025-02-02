//: C05:FriendScope2.cpp
#include <iostream>
using namespace std;

// ����������� ����������� ����������
template<class T> class Friendly;
template<class T> void f(const Friendly<T>&);

template<class T> class Friendly {
  T t;
public:
  Friendly(const T& theT) : t(theT) {}
  friend void f<>(const Friendly<T>&);
  void g() { f(*this); }
};

void h() {
  f(Friendly<int>(1));
}

template<class T>
void f(const Friendly<T>& fo) {
  cout << fo.t << endl;
}

int main() {
  h();
  Friendly<int>(2).g();
} ///:~