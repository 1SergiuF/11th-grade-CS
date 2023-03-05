#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

ifstream fin("ghiocel.in");
ofstream fout("ghiocel.out");

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef set<int> SI;

#define qi queue<int>
#define N 101

VVI G;
VB v;
VI d;
SI s;
int n, m, g, k;
int colegi[N];

void CitesteGraf();
void Bfs(int x);

int main()
{
    CitesteGraf();
    Bfs(g);
    
    int vmin = N;
    for (int i = 1; i <= k; ++i)
        vmin = min(vmin, d[colegi[i]]);

    for (int i = 1; i <= k; ++i)
        if (d[colegi[i]] == vmin)
            s.insert(colegi[i]);

    for (auto const& val : s)
        fout << val << ' ';

    return 0;
}

void Bfs(int x)
{
    qi Q;
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
    fin >> n >> m >> g;
    G = VVI(n + 1);
    v = VB(n + 1);
    d = VI(n + 1);

    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    } 

    fin >> k;
    for (int i = 1; i <= k; ++i)
        fin >> colegi[i];
}