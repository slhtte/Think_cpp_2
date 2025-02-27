#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>

template < 
    class T,
    template <class > class C
    >
class Iterator : public std::iterator<
    std::bidirectional_iterator_tag, T, ptrdiff_t>
{
    C<T> &ref;
    using cont_it = typename C<T>::iterator;
    cont_it c_it;

public:
    Iterator(C<T>& r, const cont_it& c_i) 
        : ref(r), c_it(c_i) {}  

    bool operator==(const Iterator& l)
    {
        return this->c_it == l.c_it;
    }

    bool operator!=(const Iterator& l)
    {
        return !(*this == l);
    }

    Iterator& operator++()
    {
        assert(c_it != ref.end());

        ++c_it;
        return *this;
    }

    Iterator& operator--()
    {
        assert(c_it != ref.begin());

        --c_it;
        return *this;
    }

    T operator*()
    {
        assert(c_it != ref.end());
        T val = *c_it;
        ref.erase(c_it);

        return val;
    }  
};

template <class Cont>
void print_cont(const Cont& c)
{
    std::copy(c.begin(), c.end(), 
        std::ostream_iterator<int>(std::cout, " "));
    const std::string DELIM = "\n=======\n";
    std::cout << DELIM;
}

int main()
{
    std::list<int> c = {0, 1, 2, 3, 4};
    std::list<int>::iterator it = c.begin();
    ++it; ++it;
    Iterator<int, std::list> it_beg(c, c.begin()),
        it_end(c, it);
    print_cont(c);

    while (it_beg != it_end) 
    {
        *it_beg;
        --it_end;
    }

    print_cont(c);
}