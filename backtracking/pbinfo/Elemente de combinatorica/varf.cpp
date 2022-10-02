#include <fstream>
using namespace std;

ifstream fin("varf.in");
ofstream fout("varf.out");

int n, x[12];
int a[12];
bool ok;

void Subm(int k);
void ScrieSol(int k);
bool Ok(int k);

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];

    Subm(1);

    if (!ok)
        fout << 0;

    return 0;
}

void Subm(int k)
{
    if (k > n) return;

    for (int i = x[k - 1] + 1; i <= n; ++i)
    {
        x[k] = i;
        ScrieSol(k);
        Subm(k + 1);
    }
}

void ScrieSol(int k)
{
    if (Ok(k))
    {
        ok = true;
        for (int i = 1; i <= k; ++i)
            fout << a[x[i]] << ' ';
        fout << '\n';
    }
}

bool Ok(int k)
{
    if (k < 3) return false;

    if (k == 3 && (a[x[1]] > a[x[2]] || a[x[2]] < a[x[3]]))
        return false;

    if (a[x[1]] > a[x[2]])
        return false;

    bool verif_varf = false;
    int i;
    for (i = 2; i < k; ++i)
    {
        if (a[x[i]] > a[x[i + 1]])
        {
            verif_varf = true;
            break;
        }
    }

    if (!verif_varf)
        return false;

    for (i = i + 1; i <= k; ++i)
        if (a[x[i - 1]] < a[x[i]])
            return false;

    return true;
}