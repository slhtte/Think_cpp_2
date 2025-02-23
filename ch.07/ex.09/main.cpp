#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>

#include "../../require.h"

int main(int argc, char *argv[])
{
    std::string f_name = "main.cpp";

    if (argc > 1)
    {
        f_name = argv[1];
    }

    std::ifstream in(f_name);
    assure(in);

    std::multiset<std::string> ms;
    std::string str;
    while (in >> str)
    {
        ms.insert(str);
    }

    using ms_it = std::multiset<std::string>::iterator;
    ms_it it = ms.begin();

    while (it != ms.end())
    {
        std::pair<ms_it, ms_it> p = ms.equal_range(*it);
        std::cout << *it << " : " << std::distance(p.first, p.second) << std::endl;
        it = p.second;
    }
}