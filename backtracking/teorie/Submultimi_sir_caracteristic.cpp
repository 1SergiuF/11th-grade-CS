/*
    Generarea Submultimilor unei multimi

   A   = {1, 2, 3, 4, 5}

   x[] = {0, 0, 0, 0, 0} => { } multimea vida
   x[] = {1, 0, 0, 0, 0} => {1}
   x[] = {1, 1, 0, 0, 0} => {1, 2}
         ......

    x[] = {1, 1, 1, 1, 1} => {1, 2, 3, 4, 5}

    NrSol = nr de siruri binare de lung n
    NrSol = 2^n
*/

#include <fstream>
using namespace std;

ifstream fin("submultimi_car.in");
ofstream fout("submultimi_car.out");

int n;
int x[15]; // generam siruri binare de lungime n
int nrsol;

void Subm(int k);
void ScrieSol();

int main()
{
    fin >> n;
    Subm(1);
    fout << nrsol << " solutii" ;
    return 0;
}

void Subm(int k)
{
    if (k > n)
    {
        ScrieSol();
        return;
    }

    for (int i = 0; i <= 1; ++i)
    {
        x[k] = i;
        Subm(k + 1);
    }
}

void ScrieSol()
{
    ++nrsol;
    fout << "{ ";
    for (int i = 1; i <= n; ++i)
        if (x[i] == 1)
            fout << i << ' ';
    
    fout << "}\n";
}