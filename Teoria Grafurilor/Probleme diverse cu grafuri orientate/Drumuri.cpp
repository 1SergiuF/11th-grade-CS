#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

VVI G;
VB v;
VI d;
VI noduri;

int n, m, p;

void CitesteGraf();
void Bfs(int x);

int main()
{
    CitesteGraf();
    Bfs(p);

    for (int i = 1; i <= n; ++i)
        if (d[i] % 2 == 0 && i != p)
            noduri.push_back(i);

    cout << noduri.size() << '\n';
    for (auto const& nod : noduri)
        cout << nod << ' ';

    return 0;
}

void Bfs(int x)
{
    queue<int> Q;
    v[x] = true;
    d[x] = 0;
    Q.emplace(x);

    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();

        for (auto const& y : G[x])
        {
            if (v[y]) continue;
            v[y] = true;
            d[y] = d[x] + 1;
            Q.emplace(y);
        }
    }
}

void CitesteGraf()
{
    cin >> n >> p >> m;
    G = VVI(n + 1);
    v = VB(n + 1);
    d = VI(n + 1);

    for (int i = 1, x, y; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }
}