#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int> Q;

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