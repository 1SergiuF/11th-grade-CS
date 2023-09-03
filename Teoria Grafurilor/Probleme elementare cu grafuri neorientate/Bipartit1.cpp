#include <fstream>
using namespace std;

ifstream fin("bipartit1.in");
ofstream fout("bipartit1.out");

const int N = 101;
bool a[N][N];
int stk[N];
bool ok = false;
int n, m;

void CitesteDate();
bool DifferentColors(int k);
void ParcurgeGraf(int k);
void Afiseaza();

int main()
{
    CitesteDate();
    ParcurgeGraf(1);
    Afiseaza();
    return 0;
}

void ParcurgeGraf(int k)
{
    if (k == n + 1)
    {
        ok = true;
        return;
    }

    for (int i = 0; i <= 1 && !ok; ++i)
    {
        stk[k] = i;
        if (DifferentColors(k))
            ParcurgeGraf(k + 1);
    }
}

bool DifferentColors(int k)
{
    for (int i = 1; i <= k; ++i)
        if (stk[i] == stk[k] && a[i][k])
            return false;

    return true;
}

void Afiseaza()
{
    if (ok)
    {
        fout << "DA\n";
        for (int i = 1; i <= n; ++i)
            if (stk[i] == 0)
                fout << i << ' ';
        fout << '\n';
        for (int i = 1; i <= n; ++i)
            if (stk[i] == 1)
                fout << i << ' ';
    }
    else
        fout << "NU";
}

void CitesteDate()
{
    fin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}