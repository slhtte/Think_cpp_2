//: C06:Generators.h
// ��������� ������� ���������� ����������
#ifndef GENERATORS_H
#define GENERATORS_H

#include <cstring>
#include <set>
#include <cstdlib>

// ���������, ������������ �����:
class SkipGen {
  int i;
  int skp;
public:
  SkipGen(int start = 0, int skip = 1)
    : i(start), skp(skip) {}
  int operator()() {
    int r = i;
    i += skp;
    return r;
  }
};

// ���������, �������� ���������� ��������� �����
// � ��������� �� 0 �� mod:
class URandGen {
  std::set<float> used;
  int limit;
public:
  URandGen(int lim) : limit(lim) {}
  float operator()() {
    while(true) {
      int i = int(std::rand()) % limit;
      float res = i + (float)i / 100;
      if(used.find(res) == used.end()) {
        used.insert(res);
        return res;
      }
    }
  }
};

// ��������� ��������� ��������:
class CharGen {
  static const char* source;
  static const int len;
public:
  char operator()() {
    return source[std::rand() % len];
  }
};

#endif