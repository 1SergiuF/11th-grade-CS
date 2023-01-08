
/*
	Programare Dinamica - liniara

	  3    2    4    1    6    3    8    7   10   4
	a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9] a[10]
						                            i
	  5    5    4    4    3    3    2    2    1    1 
	R[1] R[2] R[3] R[4] R[5] R[6] R[7] R[8] R[9] R[10]
											  
	  3    3    5    5    7    7    9    9    0    0
	t[1] t[2] t[3] t[4] t[5] t[6] t[7] t[8] t[9] t[10]
											 k


	Problema: det lung Lmax cmlsc pana la poz n
	Subproblema:  det lung L a cmlsc pana la poz i,
				  care INCEPE cu a[i]
	Starea subproblemei:
				  (R, i)
	Structura de date:
				  int R[1000];
				  R[i] = lung cmlsc care INCEPE cu a[i]

   Cazuri de baza (initializari):
				  R[1] = 1

	Relatia de recurenta
				   R[i] = max(R[j]) + 1
						  i + 1 <= j <= n
						  a[i] < a[j]
*/

#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlscR.in");
ofstream fout("cmlscR.out");

const int N = 1001;
int n, a[N];
int R[N];   // R[i] = lung cmlsc care INCEPE cu a[i]
int Lmax;   // solutia problemei

void CitesteSir();
void CmlscR();

int main()
{
    CitesteSir();
    CmlscR();

    fout << Lmax;

    return 0;
}

void CitesteSir()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
}

void CmlscR()  // O(n * n)
{
    for (int i = n; i >= 1; --i)
    {
        R[i] = 1;
        for (int j = i + 1; j <= n; ++j)
            if (R[j] + 1 > R[i] && a[j] > a[i])
                R[i] = R[j] + 1;

        Lmax = max(Lmax, R[i]);
    }
}