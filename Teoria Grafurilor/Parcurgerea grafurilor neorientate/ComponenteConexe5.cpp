#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("componenteconexe5.in");
ofstream fout("componenteconexe5.out");

#define N 101
bool a[N][N];
int c[N];
int k[N];
int n, m, q;
int cc;
int cnt;
vector<int> v;

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);
void DeterminaComponenteConexe();

int main()
{
    CitesteGraf();
    ComponenteConexe();
    DeterminaComponenteConexe();

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
    for (int comp = 1; comp <= cc; ++comp)
    {
        for (int x = 1; x <= n; ++x)
            if (c[x] == comp)
                v.push_back(x);

        for (int i = 1; i <= q; ++i)
            if (binary_search(v.begin(), v.end(), k[i]))
                fout << v.size() << '\n';

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