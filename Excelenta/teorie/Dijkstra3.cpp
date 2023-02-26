#include <fstream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

ifstream fin("dijkstra3.in");
ofstream fout("dijkstra3.out");

const int Inf = 0x3f3f3f3f;
using VI  = vector<int>;
using PI  = pair<int, int>;
using VP  = vector<PI>;
using VVP = vector<VP>;

VVP G;  // vector de vector de pair
VI d;   // d[x] = distanta minima de la nodul sursa la nodul x
int n;
int m;

void ReadGraph();
void Dijkstra(int x, VI& d);
void WriteDistances();

int main()
{
    ReadGraph();
    Dijkstra(1, d);
    WriteDistances();
}

void Dijkstra(int x, VI& d) // O(n * log2(m))
{
    d = VI(n + 1, Inf);
    priority_queue<PI, vector<PI>, std::greater<PI>> Q; // min-heap

    d[x] = 0;
    Q.emplace(0, x);
    int y, dx, w;

    while (!Q.empty())
    {
        auto [dx, x] = Q.top();
        //tie(dx, x) = Q.top();
        // x  = Q.top().second;
        // dx = Q.top().first;
        Q.pop();

        if (dx > d[x])  // daca x iese in coada a doua, sau treia, sau..
            continue;   // atunci iese cu o distanta mai mare decat cu distanta d[x]

        for (auto [y, w] : G[x])
        {
            //tie(y, w) = p;
            // y = p.first;
            // w = p.second;
            if (d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                Q.emplace(d[y], y);
            }
        }
    }
}

void ReadGraph()
{
    fin >> n >> m;

    G = VVP(n + 1); // acum se creeaza G[0], G[1], ... G[n]
    int x, y, w;    // w  - ponderea muchiei

    while (m--)
    {
        fin >> x >> y >> w;
        G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
    }
}

void WriteDistances()
{
    for (int i = 1; i <= n; ++i)
        if (d[i] != Inf)
            fout << d[i] << ' ';
        else
            fout << " oo";
}