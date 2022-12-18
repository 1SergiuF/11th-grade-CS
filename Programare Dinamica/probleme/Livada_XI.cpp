#include <fstream>
#include <algorithm>
using namespace std;

std::ifstream fin("livada_xi.in");
std::ofstream fout("livada_xi.out");

const int N = 102;
int a[N][N];
int dp[N][N];
int n;

void CitesteDate();
void Dinamica();

int main()
{
    CitesteDate();
    Dinamica();

    return 0;
}

void CitesteDate()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            fin >> a[i][j];
}

void Dinamica()
{
    int smin = 1e8;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = smin;

    int v = 0;

    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= i; j++)
        {
            v = min(dp[i + 1][j], dp[i][j - 1]);

            if (v != smin)
                dp[i][j] = v + a[i][j];

            else
                dp[i][j] = a[i][j];
        }
            
    for (int i = 1; i <= n; ++i)
        smin = min(smin, dp[i][i]);

    fout << smin;
}