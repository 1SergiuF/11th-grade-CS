/*
    Componente conexe - G.N.
*/

#include <fstream>
using namespace std;

ifstream fin("componenteconexe.in");
ofstream fout("componenteconexe.out");

#define N 101
bool a[N][N];
int c[N];   // c[x] comp conexa din care face parte nodul x
int n;
int cc;     // nr de compoente conexe

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);
void ScrieComponenteConexe();

int main()
{
    CitesteGraf();  // O(m)
    ComponenteConexe();
    ScrieComponenteConexe();  // O(n * n)
    return 0;
}

void ComponenteConexe()   // > O(m) aprox O(n * n)
{
    for (int nod = 1; nod <= n; ++nod)
        if (!c[nod])
        {
            cc++;
            Dfs(nod);
        }
}

void Dfs(int x)   // > O(m)
{
    c[x] = cc;
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !c[y])
            Dfs(y);
}

void ScrieComponenteConexe()  // O(n * n)
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