#include <iostream>
#include <vector>
#define N 101
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

VVI G;
VB v;
int n;
int L[N];

void CitesteGraf();
void Lant(int x, int k);
void ScrieLant(int k);

int main()
{
    CitesteGraf();
    Lant(1, 1);
    return 0;
}

void Lant(int x, int k)
{
    v[x] = true;
    L[k] = x;

    if (k == n)
    {
        ScrieLant(k);
        v[x] = false;
        exit(0);
    }

    for (int const& y : G[x])
        if (!v[y])
            Lant(y, k + 1);

    v[x] = false;
}

void CitesteGraf()
{
    cin >> n;
    G = VVI(n + 1);
    v = VB(n + 1);
    int x, y;
    int m = n * (n - 1) / 2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }
}

void ScrieLant(int k)
{
    for (int i = 1; i <= k; ++i)
        cout << L[i] << ' ';
    cout << '\n';
}