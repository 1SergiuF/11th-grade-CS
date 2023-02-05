/*
  Liste de adiacenta
*/

#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("lista2.in");
ofstream fout("lista2.out");

// Type alias-uri
using VI = vector<int>;
using SI = set<int>;
using VB = vector<bool>;
using VSI = vector<SI>;

//vector<vector<int>> G; /// G = vector vid
VSI G;  // G = vector vid
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
    G = VSI(n + 1);   // acum avem G[0], G[1], ..., G[n] - vectori vizi

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
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