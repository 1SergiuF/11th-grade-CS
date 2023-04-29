#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("zapada.in");
ofstream fout("zapada.out");

struct Edge {
    int x, y, w;

    bool operator < (Edge const& e) const noexcept
    {
        return w < e.w || (w == e.w && x < e.x)
                       || (w == e.w && x == e.w && y < e.y);
    }
};

vector<Edge> g;
vector<Edge> arb;
vector<int> t;
int cost_min;
int n, m;
int p;
int k;

void CitesteGraf();
void Init();
void Union(int x, int y);
int Find(int x);
void Kruskal();

int main()
{
    CitesteGraf();
    Init();
    Kruskal();
    fout << cost_min;
    return 0;
}

void Kruskal()
{
    sort(g.begin(), g.end());
    int c1, c2;

    for (auto const& e : g)
    {
        c1 = Find(e.x);
        c2 = Find(e.y);
        if (c1 != c2)
        {
            ++k;
            cost_min += e.w;
            arb.emplace_back(e);
            Union(c1, c2);
            if (k == n - 1)
                break;
        }
    }
}

int Find(int x)
{
    if (t[x] == x) return x;
    return t[x] = Find(t[x]);
}

void Union(int x, int y)
{
    t[x] = t[y];
}

void Init()
{
    for (int i = 1; i <= n; ++i)
        t[i] = i;
}

void CitesteGraf()
{
    fin >> n >> m;
    t = vector<int>(n + 1);
    int x, y, w;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> w;
        g.push_back({x, y, w});
    }

    fin >> p;
    for (int i = 1, d; i <= p; ++i)
    {
        fin >> d;

        ++k;
        cost_min += g[d - 1].w;
        arb.emplace_back(g[d - 1]);
        int r1 = Find(g[d - 1].x);
        int r2 = Find(g[d - 1].y);
        Union(r1, r2);  
    }
}
