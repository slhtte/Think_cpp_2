//: C05:StaticAssert1.cpp {-xo}
// Простой механизм проверки условий времени компиляции

#define STATIC_ASSERT(x) \
  do { int a[(x) ? 1 : -1]; } while (0)

int main() {
  STATIC_ASSERT(sizeof(int) <= sizeof(long)); // Проходит
  STATIC_ASSERT(sizeof(double) <= sizeof(int)); // Не проходит
} ///:~
