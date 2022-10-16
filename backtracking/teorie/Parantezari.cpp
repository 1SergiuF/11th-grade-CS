/*
    Problema Parantezarilor

    Se dau n perechi de paranteze de forma ( ).
    Sa se genereze toate expresiile corect parantezate
    obtinute cu cele n perechi de paranteze.

    Def. O expresie corect parantezata
    este de forma:
    Expr = ( E )  unde E este o expresie corect parantezata

    n = 3

    ((()))
    (()())
    (())()
    ()(())
    ()()()
*/

#include <fstream>
using namespace std;

ifstream fin("parantezari.in");
ofstream fout("parantezari.out");

int x[50]; // x[k] = 1 => '('  x[k] = 0 => ')'
int n;     // numarul de perechi de paranteze

void Parantezari(int k, int pd); // s = x[1] + x[2] + ... + x[k - 1]
void ScrieSol();
bool Ok(int k, int pd);   // pd = nr de paranteze deschise
                          // pana la poz k (inclusiv)

int main()
{
    fin >> n;
    x[1] = 1;  // pe prima pozitie - o paranteza deschisa
    Parantezari(2, 1);
    return 0;
}

void Parantezari(int k, int pd)
{
    if (k == 2 * n)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i >= 0; --i)
    {
        x[k] = i;
        if (Ok(k, pd + i))
            Parantezari(k + 1, pd + i);
    }
}

void ScrieSol()
{
    for (int i = 1; i <= 2 * n; ++i)
        if (x[i])
            fout << '(';
        else
            fout << ')';

    fout << '\n';
}

bool Ok(int k, int pd)
{
    int pi = k - pd;    // nr de paranteze inchise
    if (pi > pd) return false;
    if (pd > n) return false;

    return true;
}