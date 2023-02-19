#include <fstream>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;

ifstream fin("loc.in");
ofstream fout("loc.out");

#define INF 0x3f3f3f3f
#define N 101
#define pb push_back
#define mp make_pair

typedef set<pair<int, int>> SP;
typedef SP::iterator IT;
typedef vector<int> VI;

SP T;
IT it;
VI G[N], C[N];
int d[N], nr[N];
int n, m;

void ReadGraph();
void Dijkstra(int src);
void WriteSolution();

int main()
{
    ReadGraph();
    Dijkstra(0);
    WriteSolution();
    return 0;
}

void Dijkstra(int src)
{
    for (int i = 0; i <= n; ++i)
        d[i] = INF;

    d[src]  = 0;
    nr[src] = 1;

    T.insert(mp(0, src));
    int nod, y;

    while (!T.empty())
    {
        nod = T.begin()->second;
        T.erase(T.begin());

        for (int i = 0; i < (int)G[nod].size(); ++i)
        {
            y = G[nod][i];

            if (d[y] > d[nod] + C[nod][i])
            {
                it = T.find(mp(d[y], y));
                d[y] = d[nod] + C[nod][i];
                nr[y] = nr[nod];

                if (it != T.end())
                    T.erase(it);
                T.insert(mp(d[y], y));
            }

            else
                if (d[y] == d[nod] + C[nod][i])
                    nr[y] += nr[nod];
        }
    }
}

void WriteSolution()
{
    int maxim = -1, nod = 0;

    for (int i = 1; i <= n; ++i)
        if (maxim < nr[i])
        {
            maxim = nr[i];
            nod = i;
        }

    fout << nod << '\n' << maxim << '\n' << d[nod];
}

void ReadGraph()
{
    fin >> n;
    fin >> m;
    int x, y, z;
    while (fin >> x >> y >> z)
    {
        G[x].pb(y);
        G[y].pb(x);
        C[x].pb(z);
        C[y].pb(z);
    }
}