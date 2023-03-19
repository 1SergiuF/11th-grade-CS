/**
 Determionarea unui ciclu eulerianzs

*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("ciclueuler.in");
ofstream fout("ciclueuler.out");

struct Edge {
    int x, y;
};

using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;

VVI G;  /// graful - liste de incidenta (retine muchiile incidente fiecarui nod)
int n, m;
VB v;   /// marcam muchiile vizitate
VI ce;  /// ciclul eulerian determinat
vector<Edge> E;  // retine muchiile

void CitesteGraf();
bool GrafEulerian();
inline void Dfs(int x);
void ScrieCicluEulerian();

int main()
{
    CitesteGraf();
    if (!GrafEulerian())
        fout << "Nu este graf eulerian!";
    else
    {
        Dfs(1);
        ScrieCicluEulerian();
    }
}

inline void Dfs(int x)
{
    for (int e : G[x])
    {
        if (v[e]) continue;
        v[e] = true;
        if (E[e].x == x)
            Dfs(E[e].y);
        else
            Dfs(E[e].x);
    }
    ce.push_back(x);
}

void ScrieCicluEulerian()
{
    for (int x : ce)
        fout << x << ' ';
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVI(n + 1);
    v = VB(m + 1);
    E = vector<Edge>(m + 1);
    int x, y;
    for (int e = 1; e <= m; ++e)
    {
        fin >> x >> y;
        G[x].push_back(e);
        G[y].push_back(e);
        E[e] = {x, y};
    }
}

bool GrafEulerian()
{
    for (int x = 1; x <= n; ++x)
        if (G[x].size() % 2 == 1) // nr de muchii incidente - impar
            return false;
    return true;
}