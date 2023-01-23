//: C05:BearCorner.h
#ifndef BEARCORNER_H
#define BEARCORNER_H
#include <iostream>
using std::ostream;
 
//  лассы угощени€ (характеристики гостей):
class Milk {
public:
  friend ostream& operator<<(ostream& os, const Milk&) {
    return os << "Milk";
  }
};
class CondensedMilk {
public:
  friend ostream&
  operator<<(ostream& os, const CondensedMilk&) {
    return os << "CondensedMilk";
  }
};

class Honey {
public:
  friend ostream& operator<<(ostream& os, const Honey&) {
    return os << "Honey";
  }
};

class Cookies {
public:
  friend ostream& operator<<(ostream& os, const Cookies&) {
    return os << "Cookies";
  }
};
 
//  лассы гостей:
class Bear {
public:
  friend ostream& operator<<(ostream& os, const Bear&) {
    return os << "Theodore";
  }
};

class Boy {
public:
  friend ostream& operator<<(ostream& os, const Boy&) {
    return os << "Patrick";
  }
};
 
// ќсновной шаблон характеристик (пустой - может использоватьс€
// дл€ хранени€ базовых типов)
template<class Guest>
class GuestTraits;
 
// —пециализации характеристик дл€ типов гостей
template<> class GuestTraits<Bear> {
public:
  typedef CondensedMilk beverage_type;
  typedef Honey snack_type;
};

template<>
class GuestTraits<Boy> {
public:
  typedef Milk beverage_type;
  typedef Cookies snack_type;
};
#endif // BEARCORNER_H

//: C05:BearCorner.h
// »спользование классов характеристик
#include <iostream>
#include "BearCorner.h"
using namespace std;
 
// Ќестандартный класс характеристик
class MixedUpTraits {
public:
  typedef Milk beverage_type;
  typedef Honey snack_type;
};
 
// Ўаблон гост€ (использует класс характеристик)
template< class Guest, class traits = GuestTraits<Guest> >
class BearCorner {
  Guest theGuest;
  typedef typename traits::beverage_type beverage_type;
  typedef typename traits::snack_type snack_type;
  beverage_type bev;
  snack_type snack;
public:
  BearCorner(const Guest& g) : theGuest(g), {}
  void entertain() {
    cout << "Entertaining " << theGuest
         << " serving " << bev
         << " and " << snack << endl;
  }
};
 
int main() {
  Boy cr;
  BearCorner<Boy> pc1(cr);
  pc1.entertain();
  Bear pb;
  BearCorner<Bear> pc2(pb);
  pc2.entertain();
  BearCorner<Bear, MixedUpTraits> pc3(pb);
  pc3.entertain();
} ///:~