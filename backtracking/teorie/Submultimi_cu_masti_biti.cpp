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

ifstream fin("subm_masti_biti.in");
ofstream fout("subm_masti_biti.out");

int main()
{
    int n;
    fin >> n;
    // O(2^(n + 1)) = O(2^n)
    for (int msk = 0; msk < (1 << n); ++msk)
    {
        fout << "{ ";
        for (int b = 0; b < n; ++b) // pt fiecare bit
            if (msk & (1 << b)) // daca bitul b este in masca
                fout << b + 1 << ' ';
        fout << "}\n";
    }

    fout << (1 << n) << " solutii";

    return 0;
}