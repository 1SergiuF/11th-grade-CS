#include <iostream>
#include <cstring>
using namespace std;

int n;
int p, m;
char ch[20];
int x[15];

void Comb(int k);
void ScrieSol();

int main()
{
    cin.getline(ch + 1, 21, ' ');
    cin >> p;
    n = strlen(ch + 1);
    m = n - p;
    Comb(1);

    return 0;
}

void Comb(int k)
{
    if (k > m)
    {
        ScrieSol();
        return;
    }

    for (int i = x[k - 1] + 1; i <= n - m + k; ++i)
    {
        x[k] = i;
        Comb(k + 1);
    }
}

void ScrieSol()
{
    for (int i = 1; i <= m; ++i)
        cout << ch[x[i]];
    cout << '\n';
}