#include <fstream>
#include <vector>
using namespace std;

ifstream fin("afisarefii.in");
ofstream fout("afisarefii.out");

const int N = 101;
int n, k;
int t[N];
int f[N];
vector<vector<int>> lista_fii;

void AdaugaFii(int nod);
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> t[i];

    fin >> k;
    for (int i = 1; i <= k; ++i)
    {
        fin >> f[i];
        AdaugaFii(f[i]);
    }

    for (auto const& vec : lista_fii)
    {
        fout << vec.size() << ' ';
        for (int const& val : vec)
            fout << val << ' ';
        fout << '\n';
    }
}

void AdaugaFii(int nod)
{
    vector<int> fii_nod;
    for (int i = 1; i <= n; ++i)
        if (t[i] == nod)
            fii_nod.push_back(i);

    lista_fii.emplace_back(fii_nod);
}