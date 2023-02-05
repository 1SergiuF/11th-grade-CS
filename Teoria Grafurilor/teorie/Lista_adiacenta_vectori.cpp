/*
  Liste de adiacenta
*/

#include <fstream>
#include <vector>
using namespace std;

ifstream fin("lista1.in");
ofstream fout("lista1.out");

// Type alias-uri
using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;

//vector<vector<int>> G; /// G = vector vid
VVI G;  // G = vector vid
int n, m;

void CitesteGraf();
void ScrieListaAdiacenta();

int main()
{
    CitesteGraf();
    ScrieListaAdiacenta();
    return 0;
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVI(n + 1);   // acum avem G[0], G[1], ..., G[n] - vectori vizi

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void ScrieListaAdiacenta()
{
    for (int nod = 1; nod <= n; ++nod)
    {
        for (int x : G[nod])    // pt fiecare vecin x al lui nod
            fout << x << ' ';
        fout << '\n';
    }
}