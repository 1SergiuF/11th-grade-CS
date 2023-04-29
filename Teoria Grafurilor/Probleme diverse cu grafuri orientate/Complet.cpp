#include <iostream>
using namespace std;

const int N = 100001;
int n, aux, t, v[N];
int main()
{
    cin >> n;
    v[0] = 1, v[1] = 1;
    n = n * (n - 1) / 2;

    while (n)
    {
        t = 0;
        for (int i = 1; i <= v[0]; ++i)
        {
            aux = v[i] * 3 + t;
            v[i] = aux % 10;
            t = aux / 10;
        }

        while (t)
        {
            v[++v[0]] = t % 10;
            t /= 10;
        }

        n--;
    }

    for (int i = v[0]; i; --i)
        cout << v[i];

    return 0;
}