#include <fstream>
using namespace std;

ifstream fin("lantmaxim.in");
ofstream fout("lantmaxim.out");

#define N 21
bool a[N][N];
bool v[N];
int n, m, p, q;

int L[N];
int Lmax[N];
int kmax;

void CitesteGraf();
void Lanturi(int x, int k);
void SalveazaLant(int k);
void ScrieLant(int k);

int main()
{
    CitesteGraf();
    Lanturi(p, 1);

    ScrieLant(kmax);
    return 0;
}

void CitesteGraf()
{
    fin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }

    fin >> p >> q;
}

void Lanturi(int x, int k)
{
    v[x] = true;
    L[k] = x;

    if (k > 1)
    {
        if (x == q)
        {
            if (k > kmax)
                SalveazaLant(k);

            v[x] = false;
            return;
        }
    }

    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !v[y])
            Lanturi(y, k + 1);

    v[x] = false;
}

void SalveazaLant(int k)
{
    for (int i = 1; i <= k; ++i)
        Lmax[i] = L[i];

    kmax = k;
}

void ScrieLant(int k)
{
    for (int i = 1; i <= k; ++i)
        fout << Lmax[i] << ' ';
}