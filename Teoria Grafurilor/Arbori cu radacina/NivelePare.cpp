#include <fstream>
#include <vector>
#include <set>
using namespace std;

typedef set<int> SI;
typedef vector<SI> VSI;
typedef vector<vector<int>> VVI;

ifstream fin("nivelepare.in");
ofstream fout("nivelepare.out");

VVI lista_fii;
VSI noduri_niv;
int n;

void Dfs(int nod, int niv);
int main()
{
    fin >> n;

    lista_fii = VVI(n + 1);
    noduri_niv = VSI(n + 1);

    int t;
    for (int i = 1; i <= n; ++i)
    {
        fin >> t;
        lista_fii[t].push_back(i);
    }

    Dfs(lista_fii[0][0], 0);
    for (int i = 0; !noduri_niv[i].empty(); i += 2)
    {
        for (int const& y : noduri_niv[i])
            fout << y << ' ';
        fout << '\n';
    }

    return 0;
}

void Dfs(int nod, int niv)
{
    noduri_niv[niv].insert(nod);
    for (int const& f : lista_fii[nod])
        Dfs(f, niv + 1);
}