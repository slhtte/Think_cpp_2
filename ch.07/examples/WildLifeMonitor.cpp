//: C07:WildLifeMonitor.cpp
#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class DataPoint {
  int x, y; // Координаты
  time_t time; // Время наблюдения
public:
  DataPoint() : x(0), y(0), time(0) {}
  DataPoint(int xx, int yy, time_t tm) :
    x(xx), y(yy), time(tm) {}
  // Сгенерированный оператор = и копирующий конструктор годятся
  int getX() const { return x; }
  int getY() const { return y; }
  const time_t* getTime() const { return &time; }
};

string animal[] = {
  "chipmunk", "beaver", "marmot", "weasel",
  "squirrel", "ptarmigan", "bear", "eagle",
  "hawk", "vole", "deer", "otter", "hummingbird",
};
const int ASZ = sizeof animal/sizeof *animal;
vector<string> animals(animal, animal + ASZ);

// Информация о наблюдении в объекте Sighting,
// содержимое которого можно направить в ostream:
typedef pair<string, DataPoint> Sighting;

ostream&
operator<<(ostream& os, const Sighting& s) {
  return os << s.first << " sighted at x= " <<
    s.second.getX() << ", y= " << s.second.getY()
    << ", time = " << ctime(s.second.getTime());
}

// Генератор объектов Sighting:
class SightingGen {
  vector<string>& animals;
  enum { D = 100 };
public:
  SightingGen(vector<string>& an) : animals(an) {}
  Sighting operator()() {
    Sighting result;
    int select = rand() % animals.size();
    result.first = animals[select];
    result.second = DataPoint(
      rand() % D, rand() % D, time(0));
    return result;
  }
};

// Функция выводит меню с названиями животных,
// предлагает пользователю выбрать один из пунктов
// и возвращает индекс:
int menu() {
  cout << "select an animal or 'q' to quit: ";
  for(int i = 0; i < animals.size(); i++)
    cout <<'['<< i <<']'<< animals[i] << ' ';
  cout << endl;
  string reply;
  cin >> reply;
  if(reply.at(0) == 'q') return 0;
  istringstream r(reply);
  int i;
  r >> i; // Преобразование в int
  i %= animals.size();
  return i;
}

int main() {
  typedef multimap<string, DataPoint> DataMap;
  typedef DataMap::iterator DMIter;
  DataMap sightings;
  srand(time(0)); // Раскрутка генератора случайных чисел
  generate_n(inserter(sightings, sightings.begin()),
    50, SightingGen(animals));
  // Вывод всех элементов:
  copy(sightings.begin(), sightings.end(),
    ostream_iterator<Sighting>(cout, ""));
  // Вывод данных по выбранному типу животных:
  for(int count = 1; count < 10; count++) {
    // Выбор типа через меню:
    // int i = menu();
    // Случайный выбор (для автоматизации тестирования):
    int i = rand() % animals.size();
    // Итераторы "range" определяют начальную и конечную позиции
    // интервала с искомым ключом:
    pair<DMIter, DMIter> range =
      sightings.equal_range(animals[i]);
    copy(range.first, range.second,
      ostream_iterator<Sighting>(cout, ""));
  }
} ///:~