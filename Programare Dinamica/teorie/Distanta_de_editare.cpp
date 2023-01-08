/*
    Distanta de Editare (Lowenstein)

    Problema: det numarul minim "c" de operatii pentru 
              a transforma primele n elem din a[]
              in primele m elemente din b[] daca operatiile
              pot fi de trei tipuri:

              1) Adauga un elem in a[]
              2) Sterge un elem din a[]
              3) Modifica un elem din a[]

    Subproblema: det numarul minim "c" de operatii pentru 
              a transforma primele i elem din a[]
              in primele j elemente din b[]

    Starea:  (c, i, j)

    Struct de date:   int c[1000][1000];
              c[i][j] = numarul minim de operatii pentru 
              a transforma primele i elem din a[]
              in primele j elemente din b[]
    Cazuri de baza:
             c[i][0] = i;
             c[0][j] = j;

    Rel de recurenta:
             a) a[i] == b[j]

                c[i][j] = C[i - 1][j - 1];

             b) a[i] != b[j]

             a[1...i - 1] -> b[1...j] = > c[i - 1][j]
             c[i][j] = c[i - 1][j] + 1 (stgerg a[i])

             a[1...i] -> b[1...j - 1] = > c[i][j - 1]
             c[i][j] = c[i][j - 1] + 1 (inserez b[j])

             a[1...i - 1] -> b[1...j - 1] = > c[i - 1][j - 1]
             c[i][j] = c[i - 1][j - 1] + 1 (modific a[i] in b[j])


    c[i][j] = min({c[i - 1][j], c[i][j - 1], c[i - 1][j - 1]})
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int Dim = 1000;
char a[Dim], b[Dim];
int n, m;
int c[Dim][Dim];

/*
    c[i][j] = numarul minim de operatii pentru
    a transforma primele i elem din a[]
    in primele j elemente din b[]
*/

void CitesteSiruri();
int DistantaEditare();

int main()
{
    CitesteSiruri();
    cout << DistantaEditare();

    return 0;
}

void CitesteSiruri()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
}

int DistantaEditare()
{
    // Cazuri de baza

    for (int i = 0; i <= n; ++i)
        c[i][0] = i;

    for (int j = 0; j <= m; ++j)
        c[0][j] = j;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1];
            else
                c[i][j] = 1 + min({
                    c[i - 1][j],
                    c[i][j - 1],
                    c[i - 1][j - 1]
                });
    
    return c[n][m];
}