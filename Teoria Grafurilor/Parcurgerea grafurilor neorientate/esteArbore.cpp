#include <fstream>
#include <vector>
using namespace std;

ifstream fin("estearbore.in");
ofstream fout("estearbore.out");

const int Dim = 101;
bool a[Dim][Dim];
int niv[Dim];
int n;
int nr_muchii;
vector<bool> v;

void Dfs(int x);
void GasesteCiclu(int x, int k);
void CitesteGraf();

int main()
{
    CitesteGraf();
    if (nr_muchii != n - 1)
    {
        fout << "NU";
        return 0;
    }

    Dfs(1);

    for (int y = 1; y <= n; ++y)
        if (!v[y])
        {
            fout << "NU";
            return 0;
        }

    v.clear();
    GasesteCiclu(1, 1);

    return 0;
}

void GasesteCiclu(int x, int k)
{
    v[x] = true;
    niv[x] = k;

    for (int y = 1; y <= n; ++y)
        if (a[x][y])
        {
            if (!v[y])
                GasesteCiclu(y, k + 1);
            else
                if (niv[x] - niv[y] >= 2)
                {
                    fout << "NU";
                    return;
                }
        }

    fout << "DA";
}

void Dfs(int x)
{
    v[x] = true;
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !v[y])
            Dfs(y);
}

void CitesteGraf()
{
    fin >> n;
    v = vector<bool>(n + 1);
    int x, y;
    while (fin >> x >> y)
    {
        if (!a[x][y])
        {
            a[x][y] = a[y][x] = true;
            ++nr_muchii;
        }
    }
}