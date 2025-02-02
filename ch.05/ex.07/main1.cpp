//: C05:Exercise7.cpp {-xo}
    class Buddy {};
    
    template<class T> class My {
      int i;
    public:
      void play(My<Buddy>& s) {
        s.i = 3;
      }
    };
    int main() {
      My<int> h;
      My<Buddy> me, bud;
      h.play(bud);
      me.play(bud);
    } ///:~
