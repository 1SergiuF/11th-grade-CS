/*
    Generarea Anagramelor DISTINCTE
    in ordine crescator lexicografica
*/

#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("anagrame_dist.in");
ofstream fout("anagrame_dist.out");

char a[15]; // cuvantul
int x[15];
int n;
int nrsol;

bool Ok(int k);
void Anagrame(int k);
void ScrieSol();

int main()
{
    fin.getline(a + 1, 16);
    n = strlen(a + 1);
    sort(a + 1, a + n + 1);

    Anagrame(1);
    fout << nrsol << " solutii !";

    return 0;
}

void Anagrame(int k)
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
            Anagrame(k + 1);
    }
}

void ScrieSol()
{
    ++nrsol;
    for (int i = 1; i <= n; ++i)
        fout << a[x[i]];
    fout << '\n';
}

bool Ok(int k)
{
    for (int i = 1; i < k; ++i)
        if ((x[k] == x[i]) ||
            (a[x[k]] == a[x[i]] && x[i] > x[k]))
                return false;

    return true;
}