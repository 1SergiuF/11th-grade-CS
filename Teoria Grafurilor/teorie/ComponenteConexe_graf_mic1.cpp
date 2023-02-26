/*
    Componente conexe - G.N.
*/
#include <fstream>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

const int N = 101;
bool a[N][N];
bool v[N];
int n, m;
int cc;  // nr de compoente conexe

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);

int main()
{
    CitesteGraf(); // O(m)
    ComponenteConexe();

    return 0;
}
void ComponenteConexe() // > O(m) aprox O(n * n)
{
    for (int nod = 1; nod <= n; ++nod)
        if (!v[nod])
        {
            cc++;
            fout << "Componenta " << cc << ": ";
            Dfs(nod);
            fout << '\n';
        }

}

void Dfs(int x)
{
    v[x] = true;
    fout << x << ' ';
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !v[y])
            Dfs(y);
}

void CitesteGraf()
{
    fin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}