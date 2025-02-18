#include "Noisy.h"
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include "Sorting.h"
#include <iostream>

int main()
{
    std::vector<Noisy> v;
    std::deque<Noisy> d;
    std::list<Noisy> l;

    const unsigned SIZE = 1000000;

    std::generate_n(std::back_inserter(v), SIZE, NoisyGen());
    std::generate_n(std::back_inserter(d), SIZE, NoisyGen());
    std::generate_n(std::back_inserter(l), SIZE, NoisyGen());

    unsigned long v_sort_t = sorting(v);
    unsigned long d_sort_t = sorting(d);
    unsigned long l_sort_t = sorting(l);

    std::cout << "\nvector sorting time: " << v_sort_t << std::endl;
    std::cout << "\ndeque sorting time:  " << d_sort_t << std::endl;
    std::cout << "\nlist sorting time: "   << l_sort_t << std::endl;
}