#include <iostream>
#include <algorithm>
using namespace std;

int x[15];
int a[15];
bool pus[15];
int n;
long long vmin = 1e9 + 1;
int poz = 1;

void Perm(int k);
void ScrieSol();
bool Ok(int k);

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] < vmin)
        {
            vmin = a[i];
            poz = i;
        }
    }

    sort(a + 1, a + n + 1);

    Perm(1);

    return 0;
}

void Perm(int k)
{
    if (k > n)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;

        if (Ok(k))
        {
            pus[i] = true;
            Perm(k + 1);
            pus[i] = false;
        }
    }
}

bool Ok(int k)
{
    if (pus[x[k]]) return false;
    if (a[x[k]] == vmin && x[k] != poz) return false;

    return true;
}

void ScrieSol()
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[x[i]] == vmin && x[i] != poz) return;
        else cout << a[x[i]] << ' ';
    }

    cout << '\n';
}