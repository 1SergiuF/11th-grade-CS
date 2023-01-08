#include <fstream>
using namespace std;

ifstream fin("pacman_xi.in");
ofstream fout("pacman_xi.out");

const int N = 41;
int n, m;
long long dp[N][N];

void Dinamica();
int main()
{
    fin >> n >> m;
    Dinamica();

    return 0;
}

void Dinamica()
{
    dp[1][1] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= m; ++j)
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];

    fout << dp[n][m];
}