#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef queue<int> QI;
typedef set<int> SI;

VVI G, GT;
VI d, d2;
VB v, v2;
SI s;
int n, m, k;
string str = "Nu exista";

void CitesteGraf();
void Bfs(int x);
void BfsT(int x);

int main()
{
    CitesteGraf();
    Bfs(1);
    BfsT(1);

    for (int i = 1; i <= n; ++i)
        if (d[i] == k || d2[i] == k)
            s.insert(i);

    if (s.empty())
        cout << str;
    else
    {
        for (SI::iterator sit = s.begin(); sit != s.end(); ++sit)
            cout << *sit << ' ';
    }

    return 0;
}

void BfsT(int x)
{
    QI Q;
    v2[x] = true;
    d2[x] = 0;
    Q.emplace(x);

    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();

        for (int const& y : GT[x])
        {
            if (v2[y]) continue;
            v2[y] = true;
            d2[y] = d2[x] + 1;
            Q.emplace(y);
        }
    }
}

void Bfs(int x)
{
    QI Q;
    v[x] = true;
    d[x] = 0;
    Q.emplace(x);

    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();

        for (int const& y : G[x])
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
    cin >> n >> m >> k;
    G = GT = VVI(n + 1);
    v = v2 = VB(n + 1);
    d = d2 = VI(n + 1);

    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].emplace_back(y);
        GT[y].emplace_back(x);
    }
}