//: C07:PriorityQueue3.cpp
// ������������� ������ ������������ �������
#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool pr_bool(bool p)
{
    if (p)
    {
        cout << " true" << endl;
        return p;
    }

    cout << " false" << endl;
    return p;
}

class ToDoItem {
  char primary;
  int secondary;
  string item;
public:
  ToDoItem(string td, char pri ='A', int sec =1)
    : item(td), primary(pri), secondary(sec) {}
  friend bool operator<(
    const ToDoItem& x, const ToDoItem& y) {
      cout << x.primary << "." << x.secondary << " : "
           << y.primary  << "." << y.secondary;
    if(x.primary > y.primary)
      return pr_bool(true);
    if(x.primary == y.primary)
      if(x.secondary > y.secondary)
        return pr_bool(true);
    return pr_bool(false);
  }
  friend ostream&
  operator<<(ostream& os, const ToDoItem& td) {
    return os << td.primary << td.secondary
      << ": " << td.item;
  }
};

int main() {
  priority_queue<ToDoItem> toDoList;
  toDoList.push(ToDoItem("Empty trash", 'C', 4));
  //toDoList.push(ToDoItem("Feed dog", 'A', 1));
  toDoList.push(ToDoItem("Feed bird", 'B', 7));
  toDoList.push(ToDoItem("Mow lawn", 'C', 3));
  toDoList.push(ToDoItem("Water lawn", 'A', 1));
  toDoList.push(ToDoItem("Feed dog", 'A', 1));
  toDoList.push(ToDoItem("Feed cat", 'B', 1));
  while(!toDoList.empty()) {
    cout << toDoList.top() << endl;
    toDoList.pop();
  }
} ///:~