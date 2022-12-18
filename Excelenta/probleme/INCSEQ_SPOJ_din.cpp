#include <iostream>
using namespace std;

const int MOD = 5000000;
int dp[55][10005], v[10005], n, K, res;

int main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    //O(n^2 * k)
    for (int i = 1; i <= n; ++i)
    {
        dp[1][i] = 1;
        for (int j = 1; j < i; ++j)
            if (v[j] < v[i])
                for (int k = 2; k <= K; ++k)
                {
                    dp[k][i] += dp[k - 1][j];
                    if (dp[k][i] > MOD)
                        dp[k][i] -= MOD;
                }
    }

    for (int i = K; i <= n; ++i)
    {
        res += dp[K][i];
        if (res > MOD)
            res -= MOD;
    }

    cout << res;

    return 0;
}