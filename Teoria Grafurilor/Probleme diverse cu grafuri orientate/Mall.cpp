#include <iostream>
using namespace std;

const int N = 101;
bool a[N][N];
int n, m;
bool ok;

void CitesteGraf();
void Warshall();

int main()
{
    CitesteGraf();
    Warshall();

    int poz_cc = 0;
    for (int j = 1; j <= n; ++j)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i][j])
                ++cnt;

        if (cnt == n - 1)
        {
            ok = true;
            poz_cc = j;
            break;
        }
    }

    if (ok) cout << poz_cc;
    else cout << "NU EXISTA";

    return 0;
}

void Warshall()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && !a[i][j])
                    a[i][j] = a[i][k] && a[k][j];
}

void CitesteGraf()
{
    cin >> n >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        a[x][y] = true;
    }
}