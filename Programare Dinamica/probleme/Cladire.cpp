#include <iostream>
#include <algorithm>
using namespace std;

// ifstream fin("cladire.in");
// ofstream fout("cladire.out");

const int N = 1001;
const int MOD = 9901;

int n, m;
int dp[N][N];
int L;

void CitesteDate();
void Dinamica();

int main()
{
    CitesteDate();
    Dinamica();

    return 0;
}

void CitesteDate() { cin >> n >> m; }

void Dinamica()
{
    for (int i = 1; i <= n; ++i)
        dp[i][1] = 1;

    for (int j = 1; j <= m; ++j)
        dp[1][j] = 1;

    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= m; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    cout << dp[n][m];
}