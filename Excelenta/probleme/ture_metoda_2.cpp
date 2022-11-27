#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

ifstream fin("ture2.in");
ofstream fout("ture2.out");

const int N = 256;
int n, m, k;
bool A[N][N];
bool B[N][N];

LL c[1 << 16], c1[1 << 16], sol;

void Dinamica();

int main()
{
    fin >> n >> m >> k;

    int x, y, P;
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
        int aux = n; n = m; m = aux;
    }

    Dinamica();

    for (int i = 0; i < (1 << m); ++i)
        if (__builtin_popcount(i) == k)
            sol += c[i];

    fout << '\n' << sol;

    return 0;
}

void Dinamica()
{
    c[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        memcpy(c1, c, sizeof(c));
        for (int j = 0; j < (1 << m); ++j)
            for (int k = 0; k < m; ++k)
                if (!A[i][k] && !((1 << k) & j))
                    c[j | (1 << k)] += c1[j];

        for (int q = 0; q < (1 << m); ++q)
            fout << c[q] << ' ';
        fout << '\n';
    }
}
