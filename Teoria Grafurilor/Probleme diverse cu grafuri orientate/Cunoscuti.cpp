#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
bool a[N][N];
int n, m;
int gi[N];
int maxim;

void CitesteGraf();

int main()
{
    CitesteGraf();

    for (int i = 1; i <= n; ++i)
        if (gi[i] == maxim)
            cout << i << ' ';

    return 0;
}

void CitesteGraf()
{
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        cin >> x >> y;
        a[x][y] = true;
        gi[y]++;
        maxim = max(maxim, gi[y]);
    }
}