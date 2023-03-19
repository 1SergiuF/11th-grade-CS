#include <iostream>
using namespace std;

const int N = 200001;
int a[N];
bool f[N];
int n;
int cnt;

void Teleporteaza(int x, int poz);
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[a[i]] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        cnt = 1;
        if (f[i])
        {
            Teleporteaza(i, i);
            cout << cnt << ' ';
        }

        else
            cout << i - 1 << ' ';
    }
}

void Teleporteaza(int x, int poz)
{
    if (a[x] == poz) return;
    ++cnt;
    return Teleporteaza(a[x], poz);
}