/*
    Generarea Submultimilor unei multimi
    in ordinea creascatoare a cardinalelor submultimilor.

    NrSubm(n) = Comb(n, 0) + Comb(n, 1) + Comb(n, 2) + ... + Comb(n, n)
              = 2^n

*/

#include <fstream>
using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int n, p;
int x[15];
int nrsol;

void Submultimi();
void Comb(int k);
void ScrieSol();

int main()
{
    fin >> n >> p;
    Submultimi();

    fout << nrsol << " solutii";
    return 0;
}

void Submultimi()
{
    fout << "{ }\n";
    ++nrsol;
    for (p = 1; p <= n; ++p)
        Comb(1);
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
    fout << "{ ";
    for (int i = 1; i <= p; ++i)
        fout << x[i] << ' ';
    
    fout << "}";
    fout << '\n';
}