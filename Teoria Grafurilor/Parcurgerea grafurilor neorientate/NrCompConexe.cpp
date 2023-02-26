#include <fstream>
using namespace std;

ifstream fin("nrcompconexe.in");
ofstream fout("nrcompconexe.out");

const int N = 101;
bool a[N][N];
int c[N];
int cc;
int n, m;

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);

int main()
{
    CitesteGraf();
    ComponenteConexe();

    fout << cc;

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

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}