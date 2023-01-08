/*
	Problema (0 / 1, discreta) a rucsacului
	Knapsack problem
	Se da un rucsac de capacitate G si EXACT n 
	obiecte de greutati g[1], g[2], ... g[n]
	si valori v[1], v[2], ..., v[n]
	Se cere valoarea maxima a obiectelelor care
	pot fi puse in rucsac, stiind ca acelasi obiect
	poate fi plasat o singura data in rucsac.

*/

#include <fstream>
using namespace std;

ifstream fin("rucsac2.in");
ofstream fout("rucsac2.out");

const int N_MAX = 100, G_MAX = 10000, Inf = 1;

int g[N_MAX], v[N_MAX];     // greutatile, valoarile
int n;      // numarul de tipuri de obiect
int G;      // capacitatea rucsacului (Kg)

int c[G_MAX];   // c[j] = valoarea maxima a obiectelor
                // alese sa fie plasate in rucsac,
                // care au greutatea totala EXACT j

int vmax;       // valoarea maxima ceruta

void CitesteObiecte();
void Rucsac();      // Dinamica O(n * G)

int main()
{
    CitesteObiecte();
    Rucsac();
    fout << vmax;
}

void CitesteObiecte()
{
    fin >> n >> G;
    for (int i = 1; i <= n; ++i)
        fin >> g[i] >> v[i];
}

void Rucsac()      // Dinamica O(n * G)
{
    // cazuri de baza
    for (int j = 0; j <= G; ++j)
        c[j] = -Inf;

    c[0] = 0;
    
    for (int i = 1; i <= n; ++i)    // pentru fiecare obiect
        for (int j = G - g[i]; j >= 0; --j)
            if (c[j] != Inf &&  // daca greutatea j a fost obtinuta in rucsac
                c[j + g[i]] < c[j] + v[i])
            {
                c[j + g[i]] = c[j] + v[i];
                vmax = max(vmax, c[j + g[i]]);
            }
}