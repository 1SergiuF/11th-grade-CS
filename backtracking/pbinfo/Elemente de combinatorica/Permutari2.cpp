#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("permutari2.in");
ofstream fout("permutari2.out");

int x[15], a[15];
int n;
bool pus[15];

void Perm(int k);
void ScrieSol();

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];

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
    for (int i = 1; i <= n; ++i)
        fout << a[x[i]] << ' ';
    fout << '\n';
}