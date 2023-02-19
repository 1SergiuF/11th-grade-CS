#include <fstream>
using namespace std;

ifstream fin("componenteconexe.in");
ofstream fout("componenteconexe.out");

#define N 101
bool a[N][N];
int c[N];
int n;
int cc;

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);
void ScrieComponenteConexe();

int main()
{
    CitesteGraf();
    ComponenteConexe();
    ScrieComponenteConexe();
    return 0;
}

void ComponenteConexe()
{
    for (int nod = 1; nod <= n; ++nod)
        if (!c[nod])
        {
            cc++;
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

void ScrieComponenteConexe()
{
    fout << cc << '\n';

    for (int comp = 1; comp <= cc; ++comp)
    {
        for (int x = 1; x <= n; ++x)
            if (c[x] == comp)
                fout << x << ' ';
        fout << '\n';
    }
}

void CitesteGraf()
{
    fin >> n;
    int x, y;
    while (fin >> x >> y)
    {
        if (!a[x][y])
            a[x][y] = a[y][x] = true;
    }
}