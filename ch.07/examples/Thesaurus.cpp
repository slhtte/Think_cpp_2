//: C07:Thesaurus.cpp
// Отображение со значениями-векторами
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef map<string, vector<string> > Thesaurus;
typedef pair<string, vector<string> > TEntry;
typedef Thesaurus::iterator TIter;

// Для правильного разрешения имен:
//namespace std {
ostream& operator<<(ostream& os,const TEntry& t){
  os << t.first << ": ";
  copy(t.second.begin(), t.second.end(),
    ostream_iterator<string>(os, " "));
  return os;
}
//}

// Генератор тестовых данных для тезауруса:
class ThesaurusGen {
  static const string letters;
  static int count;
public:
  int maxSize() { return letters.size(); }
  TEntry operator()() {
    TEntry result;
    if(count >= maxSize()) count = 0;
    result.first = letters[count++];
    int entries = (rand() % 5) + 2;
    for(int i = 0; i < entries; i++) {
      int choice = rand() % maxSize();
      char cbuf[2] = { 0 };
      cbuf[0] = letters[choice];
      result.second.push_back(cbuf);
    }
    return result;
  }
};

int ThesaurusGen::count = 0;
const string ThesaurusGen::letters("ABCDEFGHIJKL"
  "MNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

// Запрос искомого "слова":
string menu(Thesaurus& thesaurus) {
  while(true) {
    cout << "Select a \"word\", 0 to quit: ";
    for(TIter it = thesaurus.begin();
      it != thesaurus.end(); it++)
      cout << (*it).first << ' ';
    cout << endl;
    string reply;
    cin >> reply;
    if(reply.at(0) == '0') exit(0); // Выход
    if(thesaurus.find(reply) == thesaurus.end())
      continue; // Слово отсутствует в списке, повторить попытку
    return reply;
  }
}

int main() {
  srand(time(0)); // Раскрутка генератора случайных чисел
  Thesaurus thesaurus;
  // Заполнение тезауруса 10 объектами:
  generate_n(
    inserter(thesaurus, thesaurus.begin()),
    10, ThesaurusGen());
  // Вывод всего содержимого:
  //copy(thesaurus.begin(), thesaurus.end(),
  //  ostream_iterator<TEntry>(cout, "\n"));
  // Построение списка ключей:
  string keys[10];
  int i = 0;
  for(TIter it = thesaurus.begin();
    it != thesaurus.end(); it++)
    keys[i++] = (*it).first;
  for(int count = 0; count < 10; count++) {
    // Ввод с консоли:
    // string reply = menu(thesaurus);
    // Случайные данные:
    string reply = keys[rand() % 10];
    vector<string>& v = thesaurus[reply];
    copy(v.begin(), v.end(),
      ostream_iterator<string>(cout, " "));
    cout << endl;
  }
} ///:~