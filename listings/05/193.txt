//: C05:UsingTypename.cpp
// typename в списке аргументов шаблона.

template<typename T> class X { };

int main() {
  X<int> x;
} ///:~