#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI  = vector<int>;
using VVI = vector<VI>;
using QI  = queue<int>;

VVI G;
VI g;
QI Q;
int n;
int cnt;

void CitesteGraf();
void Bfs(int x);

int main()
{
    CitesteGraf();
    Bfs(1);
    for (int i = 1; i <= n; ++i)
        if (g[i] == 2)
            ++cnt;

    cout << cnt;
    return 0;
}

void Bfs(int x)
{
    for (int i = 1; i <= n; ++i)
        if (g[i] == 1)
            Q.push(i);

    while (!Q.empty())
    {
        x = Q.front();
        for (auto const& y : G[x])
            if (g[y])
            {
                g[y]--;
                if (g[y] == 1)
                    Q.push(y);
            }

        g[x] = 0;
        Q.pop();
    }
}

void CitesteGraf()
{
    cin >> n;
    G = VVI(n + 1);
    g = VI(n + 1);
    for (int i = 1, x, y; i <= n; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        g[x]++;
        g[y]++;
    }
}