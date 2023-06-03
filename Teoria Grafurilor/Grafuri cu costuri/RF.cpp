#include <iostream>
using namespace std;

const int Dim = 101, Inf = 1 << 29;

int c[Dim][Dim];
int a[Dim][Dim];
int n, m;

void CitesteGraf();
void FloydWarshall();

int main()
{
    CitesteGraf();
    FloydWarshall();

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && c[i][j] == a[i][j])
                ++cnt;

    cout << cnt;

    return 0;
}

void FloydWarshall()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && c[i][j] > c[i][k] + c[k][j])
                    c[i][j] = c[i][k] + c[k][j];
}

void CitesteGraf()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                c[i][j] = Inf;

    int x, y, w;
    while (m--)
    {
        cin >> x >> y >> w;
        c[x][y] = w;
        a[x][y] = w;
    }
}