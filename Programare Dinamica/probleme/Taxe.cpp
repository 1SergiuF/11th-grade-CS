#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("taxe.in");
ofstream fout("taxe.out");

const int N = 201;
int n, m, S = 1000;
int a[N][N];
int t[N][N];

void CitesteDesert();

int main()
{
    CitesteDesert();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            t[i][j] = 1000;

    auto TupleMin = [](int a, int b, int c)
    {
        int vmin = min(a, b);
        return min(vmin, c);
    };

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            t[i][j] = TupleMin(t[i - 1][j - 1], t[i][j - 1], t[i + 1][j - 1])
                    + a[i][j];

    for (int i = 2; i <= n; ++i)
        S = min(S, t[i][m]);

    fout << S;

    return 0;
}           

void CitesteDesert()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];
}