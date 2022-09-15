#include <iostream>
using namespace std;

int x[15], c[15];
int a, b, cnt;
bool pus[15];

void Perm(int k);
void ScrieSol();

int main()
{
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        c[++cnt] = i;
    }

    Perm(1);

    return 0;
}

void Perm(int k)
{
    if (k > cnt)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i <= cnt; ++i)
    {
        x[k] = i;
        if (!pus[i])
        {
            pus[i] = true;
            Perm(k + 1);
            pus[i] = false;
        }
    }
}

void ScrieSol()
{
    for (int i = 1; i <= cnt; ++i)
        cout << c[x[i]] << ' ';
    cout << '\n';
}