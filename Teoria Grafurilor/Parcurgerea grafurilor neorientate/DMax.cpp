#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("dmax.in");
ofstream fout("dmax.out");

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

VVI G;
VB v;
VI d;
int n, m;
int _dist = -1, _dist_poz;

void CitesteGraf();
void Bfs(int x);

int main()
{
    CitesteGraf();
    Bfs(1);
    for (int i = 1; i <= n; ++i)
        if (d[i] > _dist)
        {
            _dist = d[i];
            _dist_poz = i;
        }

    fout << _dist_poz;
    
    return 0;
}

void Bfs(int x)
{
    queue<int> Q;
    v[x] = true;
    d[x] = 0;
    Q.push(x);

    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();

        for (auto const& y : G[x])
        {
            if (v[y]) continue;
            v[y] = true;
            d[y] = d[x] + 1;
            Q.push(y);
        }
    }
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVI(n + 1);
    v = VB(n + 1);
    d = VI(n + 1);

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}