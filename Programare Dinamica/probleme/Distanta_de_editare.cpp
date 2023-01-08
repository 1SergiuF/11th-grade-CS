#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int Dim = 101;

int n, m;
char a[Dim], b[Dim];
int c[Dim][Dim];
int track;

void CitesteSiruri();
int DistantaEditare();

int main()
{
    CitesteSiruri();
    cout << DistantaEditare();

    return 0;
}

void CitesteSiruri()
{
    cin.getline(a, Dim, ' ');
    cin.getline(b, Dim);

    n = strlen(a) + 1;
    m = strlen(b) + 1;
}

int DistantaEditare()
{
    for (int i = 0; i <= n; ++i)
        c[i][0] = i;

    for (int j = 0; j <= m; ++j)
        c[0][j] = j;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                track = 0;
            else
                track = 1;

            c[i][j] = min({

                1 + c[i - 1][j],
                1 + c[i][j - 1],
                track + c[i - 1][j - 1]
            });
        }
    
    return c[n][m];
}