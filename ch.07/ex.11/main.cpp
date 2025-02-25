#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

class C
{
    int priority = 0;
    char name = 'a';
    
    public:
    
    C(int p, char n) : priority(p), name(n) {}

    friend bool operator<(const C& l, const C& r)
    {
        if (l.priority < r.priority) return true;
        else if (l.priority == r.priority && l.name > r.name) return true;

        return false;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const C& c)
    {
        return os << c.name << " : " << c.priority << std::endl;
    }
};

struct C_gen
{
    const std::string names{"abcdefghijklmnopqrstuvwxyz"};

    C operator()()
    {
        char c = names[rand() % names.size()];
        int p = rand() % 50;

        return C(p, c);
    }
};

int main()
{
    const int SIZE = 20;
    std::priority_queue<C> pq;
    std::vector<C> v;
    std::srand(time_t(0));
    std::generate_n(std::back_inserter(v), SIZE, C_gen());
    for (size_t i = 0; i < v.size(); ++i)
    {
        pq.push(v[i]);
    }
    while (!pq.empty())
    {
        std::cout << pq.top();
        pq.pop();
    }
}