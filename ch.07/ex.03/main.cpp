#include <algorithm>
#include <list>
#include <iostream>
#include <ctime>

struct Generator
{
    int i{0};
    int operator()()
    {
        return i++;
    }
};

int main()
{
    std::list<int> l;
    std:generate_n(std::back_inserter(l), 1000000, Generator());
    std::reverse(l.begin(), l.end());
    std::list<int> l_copy(l);

    std::clock_t ticks = std::clock();
    l.sort();
    unsigned time_l = std::clock() - ticks;

    ticks = std::clock();
    std::sort(l_copy.begin(), l_copy.end());
    unsigned time_std = std::clock() - ticks;

    std::cout << "list::sort: " << time_l   << std::endl;
    std::cout << "std::sort: "  << time_std << std::endl;
}