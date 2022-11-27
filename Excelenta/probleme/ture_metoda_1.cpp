#include <fstream>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

ifstream fin("ture.in");
ofstream fout("ture.out");

using LL = long long;

int n, m, k;
bool A[256][256];
bool B[256][256];
int c[256][256];
LL sol;

void Dinamica();

int main()
{
    fin >> n >> m >> k;

    int P, x, y;
    fin >> P;

    while (P--)
    {
        fin >> x >> y;
        x--, y--;
        A[x][y] = true;
    }

    if (n < m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                B[j][i] = A[i][j];

        memcpy(A, B, sizeof(B));
        swap(n, m);
    }

    Dinamica();

    for (int i = 0; i < (1 << m); ++i)
        if (__builtin_popcount(i) == k)
            sol += c[n][i];

    fout << sol;
    return 0;
}

void Dinamica()
{
    c[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < (1 << m); ++j)
        {
            c[i][j] += c[i - 1][j];
            for (int k = 0; k < m; ++k)
                if (!A[i - 1][k] && !((1 << k) & j))
                    c[i][j | (1 << k)] += c[i - 1][j];
        }
    }
}