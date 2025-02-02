//	Ïî÷åìó íå êîìïèëèðóåòñÿ ñëåäóþùàÿ ïðîãðàììà?
    //: C05:Exercise8.cpp {-xo}
    #include<cmath>

    template<class T> double pythag(T a, T b, T c) {
      return (-b + sqrt(double(b*b - 4*a*c))) / 2*a;
    }

    int main() {
      pythag(1, 2, 3);
      pythag(1.0, 2.0, 3.0);
      pythag(1., 2.0, 3.0);
      pythag<double>(1, 2.0, 3.0);
    }
     ///:~