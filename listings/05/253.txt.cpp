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
	Почему не компилируется следующая программа?
    //: C05:Exercise8.cpp {-xo}
    template<class T> double pythag(T a, T b, T c) {
      return (-b + sqrt(double(b*b - 4*a*c))) / 2*a;
    }

    int main() {
      pythag(1, 2, 3);
      pythag(1.0, 2.0, 3.0);
      pythag(1, 2.0, 3.0);
      pythag<double>(1, 2.0, 3.0);
    }
    } ///:~