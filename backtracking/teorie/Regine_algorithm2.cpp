/*
   Problema Reginelor
   Sa se determine o SINGURA modalitatile de a plasa
   n regine pe o tabla de sah n x n, astfel incat
   acestea sa nu se atace.

*/

#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

ifstream fin("regine2.in");
ofstream fout("regine2.out");

int n;      // nr. regine / dimensiunile tablei
int x[15];  // x[k] = i (plasam o regina la linia i si coloana k)
int nrsol;

void Regine(int k);
bool Ok(int k);
void ScrieSol();

int main()
{
    fin >> n;
    Regine(1);
    return 0;
}

void Regine(int k)
{
    if (k > n)
    {
        ScrieSol();
        exit(0); // Iesire din PROGRAM
    }

    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (Ok(k))
            Regine(k + 1);
    }
}

bool Ok(int k)
{
    for (int i = 1; i < k; ++i)
        if (x[i] == x[k] || // atac pe orizontala
            (k - i == abs(x[k] - x[i]))) // atac pe diagonala
                return false;

    return true;
}

void ScrieSol()
{
    ++nrsol;
    fout << "Solutia nr. " << nrsol << '\n';

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (x[j] == i) fout << " R ";
            else fout << "-";
        }

        fout << '\n';
    }

    fout << "\n\n";
}