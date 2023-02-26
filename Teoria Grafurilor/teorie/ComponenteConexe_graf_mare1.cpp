/*
    Componente conexe - G.N.
*/
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;

VVI G; // graful
VB v;
VVI cc;   // componentele conexe ale grafului
VI c;     // componenta conexa curenta

int n, m;

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);
void ScrieComponenteConexe();

int main()
{
    CitesteGraf(); // O(m)
    ComponenteConexe();  // O(m)
    ScrieComponenteConexe(); // O(n)
    return 0;
}

void ScrieComponenteConexe() // O(n)
{
    fout << cc.size() << '\n';

    for (auto c : cc)
    {
        for (int x : c)
            fout << x << ' ';
        fout << '\n';
    }
}

void ComponenteConexe() // O(m)
{
    for (int nod = 1; nod <= n; ++nod)
        if (!v[nod])
        {
            c.clear();
            Dfs(nod);
            cc.push_back(c);
        }

}

void Dfs(int x) // O(m)
{
    v[x] = true;
    c.push_back(x);
    for (int y : G[x])
        if (!v[y])
            Dfs(y);
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVI(n + 1);
    v = VB(n + 1);
    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}