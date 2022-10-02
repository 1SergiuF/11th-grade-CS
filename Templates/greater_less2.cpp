#include <iostream>
#include <queue>
#include <vector>

template <typename T>
struct greater {
    bool operator() (T const& a, T const& b) const noexcept
    {
        return b < a;
    }
};

template <typename T>
struct less {
    bool operator() (T const& a, T const& b) const noexcept
    {
        return a < b;
    }
};

int main()
{
    std::priority_queue<int, std::vector<int>, ::greater<int>> Q;

    Q.push(100);
    Q.push(200);
    Q.push(400);
    Q.push(300);

    while (!Q.empty())
    {
        std::cout << Q.top() << '\n'; // elem din capul cozii
        Q.pop();     // sterge primul din coada
    }
}