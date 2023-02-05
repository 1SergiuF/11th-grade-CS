#include <fstream>
using namespace std;

ifstream fin("lantmaxim1.in");
ofstream fout("lantmaxim1.out");

const int N = 21;
int n, m, q;
bool a[N][N];
bool v[N];
int kmax;
int L[N], Lmax[N];

void CitesteGraf();
void Lanturi(int x, int k);
void SalveazaLant(int k);
void ScrieLant(int k);

int main()
{
    CitesteGraf();
    for (int x = 1; x <= n; ++x)
        if (x != q)
            Lanturi(x, 1);

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

    fin >> q;
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