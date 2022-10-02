#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("submdiv.in");
ofstream fout("submdiv.out");

int x[15], d[15];
int n, p, cnt, nrsol;

void Comb(int k);
void ScrieSol();

int main()
{
    fin >> n >> p;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            d[++cnt] = i;
            if (i * i < n)
                d[++cnt] = n / i;
        }
    }

    sort(d + 1, d + cnt + 1);
    Comb(1);
    if (nrsol == 0)
        fout << "fara solutie";
    return 0;
}

void Comb(int k)
{
    if (k > p)
    {
        ScrieSol();
        return;
    }

    for (int i = x[k - 1] + 1; i <= cnt - p + k; ++i)
    {
        x[k] = i;
        Comb(k + 1);
    }
}

void ScrieSol()
{
    ++nrsol;
    for (int i = 1; i <= p; ++i)
        fout << d[x[i]] << ' ';
    fout << '\n';
}