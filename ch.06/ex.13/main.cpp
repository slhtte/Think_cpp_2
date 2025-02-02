//: C06:CalcInventory.cpp
// Пример использования for_each()
#include <algorithm>
#include <ctime>
#include <vector>
#include "Inventory.h"
#include "PrintSequence.h"
//#include "copy_if.h"
using namespace std;

// Вычисление сводной информации:
class InvAccum {
  int quantity;
  int value;
public:
  InvAccum() : quantity(0), value(0) {}
  void operator()(const Inventory& inv) {
    quantity += inv.getQuantity();
    value += inv.getQuantity() * inv.getValue();
  }
  friend ostream&
  operator<<(ostream& os, const InvAccum& ia) {
    return os << "total quantity: "
      << ia.quantity
      << ", total value: " << ia.value;
  }
};

/*template<typename ForwardIter,
  typename OutputIter, typename UnaryPred>
OutputIter copy_if(ForwardIter begin, ForwardIter end,
  OutputIter dest, UnaryPred f) {
  while(begin != end) {
    if(f(*begin))
      *dest++ = *begin;
    ++begin;
  }
  return dest;
}*/

bool operator<(const Inventory &right, const Inventory &left)
  {
    return right.getQuantity() < left.getQuantity();
  }

int main() {
  vector<Inventory> vi;
  srand(time(0)); // Randomize
  generate_n(back_inserter(vi), 15, InvenGen());
  print(vi.begin(), vi.end(), "vi");
  InvAccum ia = for_each(vi.begin(),vi.end(), InvAccum());
  cout << ia << endl;

  cout << endl;
  copy_if(vi.begin(), vi.end(), ostream_iterator<Inventory>(cout, "\n"), bind2nd(less<Inventory>(), Inventory(0, 50, 0)));
  cout << endl;
} ///:~