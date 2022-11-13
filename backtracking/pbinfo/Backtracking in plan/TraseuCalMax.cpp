#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

ifstream fin("traseucalmax.in");
ofstream fout("traseucalmax.out");

const int N = 20,
          di[] = { -2, -1, 1, 2, 2, 1, -1, -2 },
          dj[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

#define iv (i + di[d])
#define jv (j + dj[d])

bool L[N][N];
int x[N][N];
int n, m;
int lmax;

void CitesteLabirint();
bool Ok(int i, int j);
void DeterminaMax(int i, int j, int k);
void Labirint(int i, int j, int k);
void ScrieSol();

int main()
{
    CitesteLabirint();
    DeterminaMax(1, 1, 1);
    Labirint(1, 1, 1);

    return 0;
}

void CitesteLabirint()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> L[i][j];
}

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
        return false;

    if (L[i][j])
        return false;

    if (x[i][j])
        return false;

    return true;
}

void DeterminaMax(int i, int j, int k)
{
    if (!Ok(i, j)) return;
    x[i][j] = k;

    if (i == n && j == m && k > lmax)
    {
        lmax = k;
        x[i][j] = 0;

        return;
    }

    for (int d = 0; d < 8; ++d)
        DeterminaMax(iv, jv, k + 1);

    x[i][j] = 0;
}

void Labirint(int i, int j, int k)
{
    if (!Ok(i, j)) return;
    x[i][j] = k;

    if (i == n && j == m && k == lmax)
    {
        ScrieSol();
        exit(0);
    }

    for (int d = 0; d < 8; ++d)
        Labirint(iv, jv, k + 1);

    x[i][j] = 0;
}

void ScrieSol()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            fout << x[i][j] << ' ';
        fout << '\n';
    }
}