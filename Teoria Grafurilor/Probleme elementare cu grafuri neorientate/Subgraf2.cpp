#include <iostream>
using namespace std;

#define Dim 101
bool a[Dim][Dim];
int cnt;
int n, k, m;

void CitesteDate();

int main()
{
    CitesteDate();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if ((i % k == 0 || j % k == 0) && a[i][j])
            {
                --cnt;
                a[i][j] = a[j][i] = false;
            }

    cout << cnt;
    
    return 0;
}

void CitesteDate()
{
    cin >> n >> m >> k;
    int x, y;

    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        if (!a[x][y])
        {
            ++cnt;
            a[x][y] = a[y][x] = true;
        }
    }
}