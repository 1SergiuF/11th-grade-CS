#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 20,
          di[] = { -2, -1, 1, 2, 2, 1, -1, -2 },
          dj[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int n, m, x, y;
int a[N][N];

void CitesteTabla();
bool Ok(int i, int j);
void Tabla(int i, int j, int k);
void ScrieSol();
bool VerifMetodaIntegrala();

int main()
{
    CitesteTabla();
    Tabla(x, y, 1);

    return 0;
}

void CitesteTabla()
{
    cin >> n >> m >> x >> y;
}

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m) return false;
    if (a[i][j]) return false;

    return true;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Tabla(int i, int j, int k)
{
    if (!Ok(i, j)) return;
    a[i][j] = k;

    if (i == n && j == m)
    {
        if (VerifMetodaIntegrala())
        {
            ScrieSol();
            exit(0);
        }
    }

    for (int d = 0; d < 8; ++d)
        Tabla(iv, jv, k + 1);

    a[i][j] = 0;
}

void ScrieSol()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

bool VerifMetodaIntegrala()
{
    int cnt = 0;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 0)
                ++cnt;

    if (cnt) return false;

    return true;
}