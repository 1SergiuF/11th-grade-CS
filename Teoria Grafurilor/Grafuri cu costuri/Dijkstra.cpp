#include <fstream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

#define INF 0x3f3f3f3f
using VI  = vector<int>;
using PI  = pair<int, int>;
using VP  = vector<PI>;
using VVP = vector<VP>;

VVP G;
VI d;
int n, p;

void ReadGraph();
void Dijkstra(int x, VI& d);
void WriteDistances();

int main()
{
    ReadGraph();
    Dijkstra(p, d);
    WriteDistances();
    
    return 0;
}

void Dijkstra(int x, VI& d)
{
    d = VI(n + 1, INF);
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
                Q.emplace(d[y], y);
            }
        }
    }
}

void WriteDistances()
{
    for (int i = 1; i <= n; ++i)
        fout << (d[i] != INF ? d[i] : -1) << ' ';
}

void ReadGraph()
{
    fin >> n >> p;

    G = VVP(n + 1);
    int x, y, w;

    while (fin >> x >> y >> w)
        G[x].emplace_back(y, w);
}