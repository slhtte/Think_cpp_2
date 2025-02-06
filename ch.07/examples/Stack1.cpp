//: C07:Stack1.cpp
// ������ �� ������ STL
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// ����������� �����������, ����� ������������ ������ ������ �����.
//typedef stack<string> Stack1; // �� ���������: deque<string>
typedef stack<string, vector<string> > Stack1;
//typedef stack<string, list<string> > Stack1;

int main() {
  ifstream in("Stack1.cpp");
  Stack1 textlines; // ���������� ������������ ������ ������.
  // ������ ����� � ���������� ����� � �����:
  string line;
  while(getline(in, line))
    textlines.push(line + "\n");
  // ����� ����� � �� ���������� �� �����:
  while(!textlines.empty()) {
    cout << textlines.top();
    textlines.pop();
  }
} ///:~