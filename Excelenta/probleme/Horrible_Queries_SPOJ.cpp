#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100001
#define MAX 4 * N + 1

long long tree[MAX];
long long lz[MAX], n;

void Update(int x, int a, int b, int i, int j, long long value);
long long Query(int x, int a, int b, int i, int j);
void PushDown(int nod, int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, C, p, q;
    long long v;
    bool c;

    cin >> T;
    while (T--)
    {
        cin >> n >> C;
        while (C--)
        {
            cin >> c >> p >> q;
            if (!c)
            {
                cin >> v;
                Update(1, 1, N, p, q, v);
            }

            else
                cout << Query(1, 1, N, p, q) << '\n';
        }
    }

    return 0;
}

void Update(int x, int a, int b, int i, int j, long long value)
{
    PushDown(x, a, b);
    
    if (i <= a && b <= j)
    {
        tree[x] += (b - a + 1) * value;

        if (a != b)
        {
            lz[2 * x]     += value;
            lz[2 * x + 1] += value;
        }

        return;
    }

    if (a > b || a > j || b < i) return;

    int m = a + (b - a) / 2;

    Update(2 * x, a, m, i, j, value);
    Update(2 * x + 1, m + 1, b, i, j, value);

    tree[x] = tree[2 * x] + tree[2 * x + 1];
}

long long Query(int x, int a, int b, int i, int j)
{
    PushDown(x, a, b);

    if (i <= a && b <= j)
        return tree[x];

    if (a > b || a > j || b < i) return 0;

    int m = a + (b - a) / 2;

    long long s1 = 0, s2 = 0;
    s1 = Query(2 * x, a, m, i, j);
    s2 = Query(2 * x + 1, m + 1, b, i, j);

    return s1 + s2;
}

void PushDown(int nod, int a, int b)
{
    if (lz[nod])
    {
        tree[nod] += (b - a + 1) * lz[nod];

        if (a != b)
        {
            lz[2 * nod]     += lz[nod];
            lz[2 * nod + 1] += lz[nod];
        }

        lz[nod] = 0;
    }
}