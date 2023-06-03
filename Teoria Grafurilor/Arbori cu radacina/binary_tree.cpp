#include <iostream>
using namespace std;

int DistanceBetweenNodes(int u, int v) 
{
    int distance = 0;

    while (u != v) 
    {
        if (u > v)
            u >>= 1;
        else
            v >>= 1;

        distance++;
    }

    return distance;
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) 
    {
        int u, v;
        cin >> u >> v;

        int distance = DistanceBetweenNodes(u, v);
        cout << distance << '\n';
    }
}
