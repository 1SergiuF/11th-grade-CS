#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX = 1001, G_MAX = 10001, Inf = 1;
int n, G;
int g[N_MAX], v[N_MAX];
int k[G_MAX];
int vmax;

void CitesteDate();
void Knapsack();

int main()
{
    CitesteDate();
    Knapsack();
    cout << vmax;
    return 0;
}

void CitesteDate()
{
    cin >> n >> G;
    for (int i = 1; i <= n; ++i)
        cin >> g[i] >> v[i];
}

void Knapsack()
{
    for (int j = 0; j <= G; ++j)
        k[j] = -Inf;

    k[0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = G - g[i]; j >= 0; --j)
            if (k[j] != Inf &&
                k[j + g[i]] < k[j] + v[i])
            {
                k[j + g[i]] = k[j] + v[i];
                vmax = max(vmax, k[j + g[i]]);
            }
}