#include <fstream>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

ifstream fin("picard.in");
ofstream fout("picard.out");

typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVP;
typedef set<int> SI;

const int Inf = 0x3f3f3f3f;
VVP G;
VB v;
VI d;
VI S;
SI planete;
int n, m;
int vmax;

void CitesteGraf();
void Dijkstra(int x, VI& d, int i);

int main()
{
    CitesteGraf();
    for (int i = 1; i <= n; ++i)
    {
        Dijkstra(i, d, i);
        d.clear();
        d = VI(n + 1, Inf);
    }

    for (int i = 1; i <= n; ++i)
        if (S[i] == vmax)
            planete.insert(i);

    for (auto const& p : planete)
        fout << p << ' ';

    return 0;
}

void Dijkstra(int x, VI& d, int i)
{
    d = VI(n + 1, Inf);
    priority_queue<PI, vector<PI>, std::greater<PI>> Q;

    d[x] = 0;
    Q.emplace(0, x);
    int y, dx, w;

    while (!Q.empty())
    {
        x  = Q.top().second;
        dx = Q.top().first;
        Q.pop();

        if (dx > d[x])
            continue;

        for (auto const& g : G[x])
        {
            y = g.first;
            w = g.second;
            if (d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                S[i] += d[y];
                Q.emplace(d[y], y);
            }
        }
    }

    vmax = max(vmax, S[i]);
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVP(n + 1);
    v = VB(n + 1);
    S = VI(n + 1);

    int x, y, w;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> w;
        G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
    }
}