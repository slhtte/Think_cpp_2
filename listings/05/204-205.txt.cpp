//: C05:ApplySequence.h
// Применение функции к элементам последовательного контейнера STL

// Константная функция, 0 аргументов,
// произвольный тип возвращаемого значения:
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)() const) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end()) {
    ((*it++)->*f)();
  }
}

// Константная функция, 1 аргумент,
// произвольный тип возвращаемого значения:
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A) const, A a) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end()) {
    ((*it++)->*f)(a);
  }
}

// Константная функция, 2 аргумента,
// произвольный тип возвращаемого значения:
template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2) const,
    A1 a1, A2 a2) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end()) {
    ((*it++)->*f)(a1, a2);
  }
}

// Неконстантная функция, 0 аргументов,
// произвольный тип возвращаемого значения:
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)()) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end()) {
    ((*it++)->*f)();
  }
}

// Неконстантная функция, 1 аргумент,
// произвольный тип возвращаемого значения:
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A), A a) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end()) {
    ((*it++)->*f)(a);
  }
}

// Неконстантная функция, 2 аргумента,
// произвольный тип возвращаемого значения:
template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2),
    A1 a1, A2 a2) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end()) {
    ((*it++)->*f)(a1, a2);
  }
}

// И т. д. для наиболее вероятных аргументов ///:~