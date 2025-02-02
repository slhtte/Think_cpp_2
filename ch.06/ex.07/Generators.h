//: C06:Generators.h
// Различные способы заполнения интервалов
#ifndef GENERATORS_H
#define GENERATORS_H

#include <cstring>
#include <set>
#include <cstdlib>

// Генератор, пропускающий числа:
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

// Генератор, выдающий уникальные случайные числа
// в интервале от 0 до mod:
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

// Генератор случайных символов:
class CharGen {
  static const char* source;
  static const int len;
public:
  char operator()() {
    return source[std::rand() % len];
  }
};

#endif