#ifndef _SORTING_H_
#define _SORTING_H_

#include <ctime>
#include <algorithm>
#include <list>
#include <iostream>

//#include "Noisy.h"

template< typename Type, template< typename T = Type> typename Cont>
unsigned long sorting(Cont<>& c)
{
    typename Cont<>::iterator it_b = c.begin(), it_e = c.end();
    std::reverse(it_b, it_e);
    it_b = c.begin(), it_e = c.end();

    std::clock_t ticks = std::clock();

    std::sort(it_b, it_e);

    return std::clock() - ticks;
}

template<>
unsigned long sorting(std::list<Noisy>& c)
{
    std::cout << "\nsorting list...\n";

    std::reverse(c.begin(), c.end());

    std::clock_t ticks = std::clock();

    c.sort();

    return std::clock() - ticks;
}

#endif