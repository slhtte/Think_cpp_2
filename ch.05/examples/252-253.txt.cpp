 //: C05:Exercise4.cpp {-xo}
    class Noncomparable {};

    struct HardLogic {
      Noncomparable nc1, nc2;
      void compare() {
         return nc1 == nc2; // Ошибка компилятора
      }
    };

    template<class T> struct SoftLogic {
      Noncomparable nc1, nc2;
      void noOp() {}
      void compare() {
        nc1 == nc2;
      }
    };

    int main() {
      SoftLogic<Noncomparable> l;
      l.noOp();
    } ///:~