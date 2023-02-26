#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 101
#define INF 0x3f3f3f3f

int G[N][N];
double medii[N];
double dp[N];
int n, m;

void CitesteGraf();

int main()
{
    CitesteGraf();

    for (int i = 1; i <= n; ++i)
    {
        int sum = 0, cnt = 0;
        for (int j = 1; j <= n; ++j)
            if (G[i][j])
            {
                sum += G[i][j];
                ++cnt;
            }

        medii[i] = (double) (sum / cnt);
        sum = cnt = 0;
    }

    dp[0] = INF;
    for (int i = 1; i <= n; ++i)
        dp[i] = min(dp[i - 1], medii[i]);

    int c = 1;
    while (dp[c] != dp[n])
        ++c;

    cout << c;

    return 0;
}

void CitesteGraf()
{
    cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; ++i)
    {
        cin >> x >> y >> w;
        G[x][y] = G[y][x] = w;
    }
}
