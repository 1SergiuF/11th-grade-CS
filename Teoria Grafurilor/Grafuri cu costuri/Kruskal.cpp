#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("kruskal.in");
ofstream fout("kruskal.out");

struct Edge {
    int x, y, w;

    bool operator < (Edge const& e) const noexcept
    {
        return w < e.w;
    }
};

vector<Edge> g;
vector<Edge> arb;
vector<int> t;
int n, m;
int cost_min;

void Union(int x, int y);
void Init();
int Find(int x);
void ReadGraph();
void Kruskal();
void Print();

int main()
{
    ReadGraph();
    Init();
    Kruskal();
    Print();

    return 0;
}

void Kruskal()
{
    sort(g.begin(), g.end());
    int k = 0;
    int c1, c2;

    for (auto const& e : g)
    {
        c1 = Find(e.x);
        c2 = Find(e.y);
        if (c1 != c2)
        {
            cost_min += e.w;
            arb.push_back(e);
            Union(c1, c2);
            ++k;
            if (k == n - 1) break;
        }
    }
}

void Print()
{
    fout << cost_min << '\n';
    for (auto const& e : arb)
        fout << e.x << ' ' << e.y << '\n';
}

void ReadGraph()
{
    fin >> n >> m;

    t = vector<int>(n + 1);
    for (int i = 1, x, y, w; i <= m; ++i)
    {
        fin >> x >> y >> w;
        g.push_back({x, y, w});
    }
}

int Find(int x)
{
    if (x == t[x]) return x;
    return t[x] = Find(t[x]);
}

void Init()
{
    for (int i = 1; i <= n; ++i)
        t[i] = i;
}

void Union(int x, int y)
{
    t[x] = y;
}