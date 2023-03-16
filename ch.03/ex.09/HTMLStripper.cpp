//: C03:HTMLStripper.cpp {RunByHand}
//{L} ReplaceAll
// ������ ��� �������� ����� � �������� HTML
#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "ReplaceAll.h"
#include "../../require.h"
using namespace std;

void print_tag(const string& tag)
{
  cout << "Tag name is " << tag << endl;
}

string& stripHTMLTags(string& s) {
  static bool inTag = false;
  bool done = false;
  while (!done) {
    if (inTag) {
      // � ���������� ������ �������, �� �� ���������� ��� HTML.
      // ���������� ����� '>'.
      size_t rightPos = s.find('>');
      if (rightPos != string::npos) {
        inTag = false;
        s.erase(0, rightPos + 1);
      }
      else {
        done = true;
        s.erase();
      }
    }
    else {
      // ����� ������ ����:
      size_t leftPos = s.find('<');
      if (leftPos != string::npos) {
        // ���������, ����������� �� ��� � ������� ������
        size_t rightPos = s.find('>');
        if (rightPos == string::npos) {
          inTag = done = true;
          s.erase(leftPos);
        }
        else
        {
          if (s[leftPos + 1] != '/')
          {
            print_tag(string(s.substr(leftPos + 1, rightPos - leftPos - 1)));
          }
          s.erase(leftPos, rightPos - leftPos + 1);
        }
      }
      else
        done = true;
    }
  }
  // �������� ���� ����������� �������� HTML
  replaceAll(s, "&lt;", "<");
  replaceAll(s, "&gt;", ">");
  replaceAll(s, "&amp;", "&");
  replaceAll(s, "&nbsp;", " ");
  // E�o.�a.
  return s;
}

int main(int argc, char* argv[]) {
  requireArgs(argc, 1,
    "usage: HTMLStripper InputFile");
  ifstream in(argv[1]);
  assure(in, argv[1]);
  string s;
  while(getline(in, s))
    if (!stripHTMLTags(s).empty())
      cout << s << endl;
} ///:~