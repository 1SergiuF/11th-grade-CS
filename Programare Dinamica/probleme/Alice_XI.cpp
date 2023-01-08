#include <fstream>
using namespace std;

ifstream fin("alice_xi.in");
ofstream fout("alice_xi.out");

const int N = 101;
long long n, dp[N][N];

void Dinamica();
int main()
{
    fin >> n;
    Dinamica();

    return 0;
}

void Dinamica()
{
    long long moduri = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];

    for (int j = 1; j <= n; ++j)
        moduri += dp[n][j];

    fout << moduri;
}