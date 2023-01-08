#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX = 1001, G_MAX = 10001, Inf = G_MAX;
int n, G;
int g[N_MAX];
int c[G_MAX];

void CitesteDate();
void Rucsac();

int main()
{
    CitesteDate();
    Rucsac();
    if (c[G] == Inf) cout << "NU";
    else cout << c[G];
    return 0;
}

void CitesteDate()
{
    cin >> n >> G;
    for (int i = 1; i <= n; ++i)
        cin >> g[i];
}

void Rucsac()
{
    for (int j = 1; j <= G; ++j)
        c[j] = Inf;

    for (int i = 1; i <= n; ++i)
        for (int j = G; j >= g[i]; j--)
            if (c[j] > c[j - g[i]] + 1)
                c[j] = c[j - g[i]] + 1;
}