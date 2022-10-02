/*
    Generarea COMBINARILOR de n luate cate k

    Comb(n, k) este:
    1. Numarul de posibilitati de a alege k elemente
       dintr-o multime cu n elemente a.i.
       ORDINEA NU CONTEAZA.
    2. Numarul de submultimi cu k elemente ale unei multimi
       cu n elemente.
*/

#include <fstream>
using namespace std;

ifstream fin("comb.in");
ofstream fout("comb.out");

int n, p; // geneneram comb(n, p)
int x[15];
int nrsol;

void Comb(int k);
void ScrieSol();

int main()
{
    fin >> n >> p;
    Comb(1);

    fout << nrsol << " solutii";

    return 0;
}

void Comb(int k)
{
    if (k > p)
    {
        ScrieSol();
        return;
    }

    for (int i = x[k - 1] + 1; i <= n - p + k; ++i)
    {
        x[k] = i;
        Comb(k + 1);
    }
}

void ScrieSol()
{
    ++nrsol;
    for (int i = 1; i <= p; ++i)
        fout << x[i] << ' ';
    fout << '\n';
}