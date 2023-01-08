/*
	Programare Dinamica - liniara

	  3    2    4    1    6    3    8    7   10   4
	a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9] a[10]
						  i
	  1    1    2    1    3    2    4    4    5     3
	L[1] L[2] L[3] L[4] L[5] L[6] L[7] L[8] L[9] L[10]
					                          k                
					 
	  0	   0 	1	 0    3    2    5    5    7     6
	t[1] t[2] t[3] t[4] t[5] t[6] t[7] t[8] t[9] t[10]
	                                         k


	Problema: det lung Lmax cmlsc pana la poz n
	Subproblema:  det lung L a cmlsc pana la poz i,
				  care SE TERMINA cu a[i]
	Starea subproblemei:
				  (L, i)
	Structura de date:
				  int L[1000];
				  L[i] = lung cmlsc care SE TERMINA cu a[i]

   Cazuri de baza (initializari):
				  L[1] = 1

	Relatia de recurenta
				   L[i] = max(L[j]) + 1
						  1 <= j < i
						  a[j] < a[i]
*/

#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlscL.in");
ofstream fout("cmlscL.out");

const int N = 1001;
int n, a[N];
int L[N];   // L[i] = lung cmlsc care SE TERMINA cu a[i]
int Lmax;   // solutia problemei

void CitesteSir();
void CmlscL();

int main()
{
    CitesteSir();
    CmlscL();

    fout << Lmax;

    return 0;
}


void CitesteSir()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
}

void CmlscL()  // O(n * n)
{
    for (int i = 1; i <= n; ++i)
    {
        L[i] = 1;
        for (int j = 1; j < i; ++j)
            if (L[j] + 1 > L[i] && a[j] < a[i])
                L[i] = L[j] + 1;

        Lmax = max(Lmax, L[i]); 
    }
}