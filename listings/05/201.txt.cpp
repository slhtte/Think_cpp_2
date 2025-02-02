//: C05:TemplateFunctionAddress.cpp {-mwcc}
// Получение адреса функции, сгенерированной из шаблона

template <typename T> void f(T*) {}

void h(void (*pf)(int*)) {}

template <typename T>
  void g(void (*pf)(T*)) {}

int main() {
  // Полная спецификация типа:
  h(&f<int>);
  // Вычисление типа:
  h(&f);
  // Полная спецификация типа:
  g<int>(&f<int>);
  // Автоматическое определение типа:
  g(&f<int>);
  // Неполная (но достаточная) спецификация типа
  g<int>(&f);
} ///:~