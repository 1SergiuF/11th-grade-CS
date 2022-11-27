#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1001;

int n, a[N];
int k;

int BinarySearch(int v);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int v;

    for (int i = 1; i <= n; ++i)
    {
        cin >> v;
        int poz = BinarySearch(v);

        if (poz != -1)
            a[poz] = v;
        else
            a[++k] = v;
    }

    cout << k;

    return 0;
}

int BinarySearch(int v)
{
    int poz = -1;

    if (v < a[k])
        return poz;

    int st = 1, dr = k, m;

    while (st <= dr)
    {
        m = (st + dr) / 2;

        if (v > a[m])
        {
            poz = m;
            dr = m - 1;
        }

        else
            st = m + 1;
    }

    return poz;
}