#include <fstream>
#include <algorithm>
#include <tuple>
using namespace std;

ifstream fin("comori.in");
ofstream fout("comori.out");

const int N = 201;
int n, m;
int V;
int a[N][N];
int c[N][N];

void CitesteDesert();
int main()
{
    CitesteDesert();

    auto TupleMax = [](int a, int b, int c)
    {
        int vmax = max(a, b);
        return max(vmax, c);
    };


    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            c[i][j] = TupleMax(c[i - 1][j - 1], c[i - 1][j], c[i - 1][j + 1])
                      + a[i][j];

    for (int i = 1; i <= m; ++i)
        V = max(V, c[n][i]);

    fout << V;

    return 0;

}

void CitesteDesert()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];
}