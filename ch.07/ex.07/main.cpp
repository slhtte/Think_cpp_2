#include <stack>
#include <iostream>

#include "../../require.h"

int main(int argc, char* argv[])
{
    requireArgs(argc, 1);

    using ull = unsigned long long;
    std::stack<ull> s;
    s.push(0);
    s.push(1);

    int arg = std::atoi(argv[1]);
    while ((arg--) > 1)
    {
        ull i_1 = s.top();
        s.pop();

        ull i_2 = s.top();
        s.pop();

        s.push(i_2);
        s.push(i_1);
        s.push(i_2 + i_1);
    }

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}