#include <iostream>
#include <algorithm>
using namespace std;

const int Dim = 16;

int n, x[Dim], a[Dim];
bool pr[Dim], pus[Dim];

void Perm(int k);
bool Ok(int k);
bool Prim(int n);
void ScrieSol();

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        if(Prim(a[i]))
            pr[i] = true;
    }

    for(int i = 1; i < n; ++i)
    {
        if(!pr[i])
        {
            for(int j = i + 1; j <= n; ++j)
            {
                if(!pr[j])
                    if(a[i] > a[j])
                        swap(a[i], a[j]);
            }
        }
    }

    Perm(1);

    return 0;
}

void Perm(int k)
{
    if(k > n)
    {
        ScrieSol();
        return;
    }

    for(int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if(Ok(k))
        {
            pus[i] = true;
            Perm(k + 1);
            pus[i] = false;
        }
    }
}

bool Ok(int k)
{
    if(pus[x[k]])
        return false;

    if(pr[x[k]] && x[k] != k)
        return false;

    return true;
}

bool Prim(int n)
{
    if(n < 2)
        return false;

    if(n == 2)
        return true;

    if(!(n % 2))
        return false;

    for(int i = 3; i * i <= n; i += 2)
        if(!(n % i))
            return false;

    return true;
}

void ScrieSol()
{
    for(int i = 1; i <= n; ++i)
        cout << a[x[i]] << ' ';

    cout << '\n';
}