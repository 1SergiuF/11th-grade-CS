/*
    Generarea Permutarilor literelor
    unui cuvant (ANAGRAME) - toate literele cuvantului sunt distincte
    in ordine crescator lexicografica
*/

#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("anagrame.in");
ofstream fout("anagrame.out");

char a[15];
int x[15];
bool pus[15];
int n;
int nrsol;

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
        if (!pus[i])
        {
            pus[i] = true;
            Anagrame(k + 1);
            pus[i] = false;
        }
    }
}

void ScrieSol()
{
    ++nrsol;
    for (int i = 1; i <= n; ++i)
        fout << a[x[i]];
    fout << '\n';
}