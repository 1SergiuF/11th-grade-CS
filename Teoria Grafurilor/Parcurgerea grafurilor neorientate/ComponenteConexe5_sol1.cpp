#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

ifstream fin("componenteconexe5.in");
ofstream fout("componenteconexe5.out");

#define N 1001
bool a[N][N];
int c[N];
int k[N];
int n, m, q;
int cc;
vector<int> nr_noduri;

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);
void DeterminaComponenteConexe();

int main()
{
    CitesteGraf();
    ComponenteConexe();
    DeterminaComponenteConexe();

    for (int i = 1; i <= q; ++i)
        fout << nr_noduri[k[i]] << '\n';

    return 0;
}

void ComponenteConexe()
{
    for (int nod = 1; nod <= n; ++nod)
        if (!c[nod])
        {
            ++cc;
            Dfs(nod);
        }
}

void Dfs(int x)
{
    c[x] = cc;
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !c[y])
            Dfs(y);
}

void DeterminaComponenteConexe()
{
    nr_noduri = vector<int>(n + 1);
    int cnt = 0;
    vector<int> v;

    for (int comp = 1; comp <= cc; ++comp)
    {
        for (int x = 1; x <= n; ++x)
            if (c[x] == comp)
            {
                ++cnt;
                v.push_back(x);
            }

        for (auto const& val : v)
            nr_noduri[val] = cnt;

        cnt = 0;
        v.clear();
    }
}

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }

    fin >> q;
    for (int i = 1; i <= q; ++i)
        fin >> k[i];
}