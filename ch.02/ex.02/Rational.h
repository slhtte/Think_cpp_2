//: C02:Rational.h {-xo}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>
#include <stdexcept>
#include <string>

class Rational {
public:
  class Rational_Exception : public std::runtime_error 
  {
  public:
    Rational_Exception(const std::string &msg="") : runtime_error(msg) {}
  };
  Rational(int numerator = 0, int denominator = 1);
  Rational operator-() const;
  friend Rational operator+(const Rational&,
                            const Rational&);
  friend Rational operator-(const Rational&,
                            const Rational&);
  friend Rational operator*(const Rational&,
                            const Rational&);
  friend Rational operator/(const Rational&,
                            const Rational&);
  friend std::ostream&
  operator<<(std::ostream&, const Rational&);
  friend std::istream&
  operator>>(std::istream&, Rational&);
  Rational& operator+=(const Rational&);
  Rational& operator-=(const Rational&);
  Rational& operator*=(const Rational&);
  Rational& operator/=(const Rational&);
  friend bool operator<(const Rational&,
                        const Rational&);
  friend bool operator>(const Rational&,
                        const Rational&);
  friend bool operator<=(const Rational&,
                         const Rational&);
  friend bool operator>=(const Rational&,
                         const Rational&);
  friend bool operator==(const Rational&,
                         const Rational&);
  friend bool operator!=(const Rational&,
                         const Rational&);
private:
  double m;
  int q;

  void __normalize();
  double __denormalize() const;
};
#endif // RATIONAL_H ///:~
