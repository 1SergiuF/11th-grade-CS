#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("perm_sir.in");
ofstream fout("perm_sir.out");

int x[15];
int a[15];
bool pus[15];
int n;
int nrsol;

void Perm(int k);
void ScrieSol();

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];

    sort(a + 1, a + n + 1);
    Perm(1);

    fout << nrsol << " solutii !";

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
    ++nrsol;
    for (int i = 1; i <= n; ++i)
        fout << a[x[i]] << ' ';
    fout << '\n';
}