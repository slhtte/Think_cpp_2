#include <stack>
#include <cstdlib>

int main()
{
    std::stack<int> source, sorted, losers;
    const int SIZE = 5;

    std::srand(time_t(0));
    for (int i = 0; i < 50; ++i)
    {
        source.push(rand() % 100);
    }

    std::stack<int> &source_ref = source, &losers_ref = losers;
    
    do
    {
        sorted.push(source_ref.top());
        source_ref.pop();

        while (!source_ref.empty() && !sorted.empty())
        {
            if (source_ref.top() >= sorted.top())
            {
                losers.push(sorted.top());
                sorted.pop();
                sorted.push(source_ref.top());
                source_ref.pop();
            }
            else
            {
                losers_ref.push(source_ref.top());
                source_ref.pop();
            }
        }

        if (source_ref.empty()) source_ref.swap(losers_ref);
    }
    while (!source.empty() || !losers.empty());

    exit(0);
}