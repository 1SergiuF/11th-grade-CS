#include <iostream>
using namespace std;

int x[41];
int n, c, p;

void CaineSiPisici(int k, int s);
void ScrieSol();
bool Ok(int k, int s);

int main()
{
    cin >> c >> p;
    n = c + p;
    x[1] = 0;
    x[n] = 1;  

    CaineSiPisici(2, 1);
    return 0;
}

void CaineSiPisici(int k, int s)
{
    if (k > n - 1)
    {
        ScrieSol();
        return;
    }

    for (int i = 0; i <= 1; ++i)
    {
        x[k] = i;
        if (Ok(k, s + i))
            CaineSiPisici(k + 1, s + i);
    }
}

bool Ok(int k, int s)
{
    int nr_c = k - s + 1;
    if (s > p) return false;
    if (nr_c > c) return false;

    if (k > 2 && x[k - 2] == 0 && x[k - 1] == 1 && x[k] == 0) return false;

    return true;
}

void ScrieSol()
{
    for (int i = 1; i <= n; ++i)
        if (x[i])
            cout << 'P';
        else
            cout << 'C';

    cout << '\n';
}