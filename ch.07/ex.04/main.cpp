#include <cstdlib>
#include <set>
#include <algorithm>
#include <iostream>

struct Int_Gen
{
    int operator()()
    {
        return std::rand() % 20;
    }
};

int main()
{
    const unsigned SIZE = 100;

    std::multiset<int> ms;
    std::srand(time_t());
    std::generate_n(std::inserter(ms, ms.begin()), SIZE, Int_Gen());

    std::multiset<int>::iterator it = ms.begin();
    using ms_iter = std::multiset<int>::iterator;
    while (it != ms.end())
    {
        std::pair<ms_iter, ms_iter> p = ms.equal_range(*it);
        std::cout << *it << " : " << std::distance(p.first, p.second) << std::endl;
        it = p.second;
    }
}