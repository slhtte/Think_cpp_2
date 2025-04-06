#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <list>

const size_t SIZE = 100'000'000;

template<typename Stack>
clock_t push(Stack &s, const std::vector<unsigned> &v)
{
    size_t counter = 0;
    clock_t ticks = clock();

    while (counter < SIZE)
    {
        s.push(v[counter]);
        ++counter;
    }

    return clock() - ticks;
}

template<typename Stack>
clock_t top_and_pop(Stack &s)
{
    clock_t ticks = clock();

    while (!s.empty())
    {
        unsigned tmp = s.top();
        s.pop();
    }

    return clock() - ticks;
}

int main()
{
    std::vector<unsigned> v(SIZE);

    std::srand(std::time(nullptr));

    for (size_t i = 0; i < v.size(); ++i)
    {
        v[i] = std::rand();
    }

    std::stack<unsigned, std::vector<unsigned> > s_v;
    clock_t vector_ticks = push(s_v, v);

    std::stack<unsigned, std::list<unsigned> > s_l;
    clock_t list_ticks = push(s_l, v);

    std::stack<unsigned> s_d;
    clock_t deque_ticks = push(s_d, v);

    std::cout << "push to deque: "  << deque_ticks  << '\n';
    std::cout << "push to vector: " << vector_ticks << '\n';
    std::cout << "push to list: "   << list_ticks   << '\n';

    deque_ticks = top_and_pop(s_d);
    vector_ticks = top_and_pop(s_v);
    list_ticks = top_and_pop(s_l);

    std::cout << "top&pop to deque: "  << deque_ticks  << '\n';
    std::cout << "top&pop to vector: " << vector_ticks << '\n';
    std::cout << "top&pop to list: "   << list_ticks   << '\n';
}