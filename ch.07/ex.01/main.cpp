#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include "../../require.h"

int main(int argc, char* argv[])
{
    std::string fname{"main.cpp"};

    if (argc > 1) fname = argv[1];

    std::ifstream in(fname);
    assure(in, fname);

    char c;
    std::set<char> s;
    while (in >> c)
    {
        s.insert(c);
    }

    std::copy(s.begin(), s.end(), std::ostream_iterator<char>(std::cout, "\n"));
}