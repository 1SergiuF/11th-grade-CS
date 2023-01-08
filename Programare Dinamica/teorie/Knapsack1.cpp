/*
	Problema (0 / 1, discreta) a rucsacului
	Knapsack problem
	Se da un rucsac de capacitate G si n TIPURI
	de obiecte de greutati g[1], g[2], ... g[n]
	si valori v[1], v[2], ..., v[n]
	Se cere valoarea maxima a obiectelelor care
	pot fi puse in rucsac, stiind ca: exista
	oricate obiecte din fiecare tip.

*/

#include <fstream>
using namespace std;

ifstream fin("rucsac1.in");
ofstream fout("rucsac1.out");

const int N_MAX = 100, G_MAX = 10000, Inf = 1;

int g[N_MAX], v[N_MAX]; // greutatile, valorile
int n;  // numarul de tipuri de obiecte
int G;  // capacitatea rucsacului (Kg)

int c[G_MAX];   // c[j] = valoarea maxima a obiectelor
                // alese sa fie plasate in rucsac,
                // care au greutatea totala EXACT j

int vmax;   // valoarea maxima ceruta
int t[G_MAX];   // t[j] = i (s-a obtinut greautatea j
                // prin adaugarea la final a obiectului i)

int gr_ob = G_MAX;

void CitesteObiecte();
void Rucsac();  // Dinamica O(n * G)
void Obiecte(int gr);

int main()
{
    CitesteObiecte();
    Rucsac();

    fout << vmax << '\n';
    Obiecte(gr_ob);
}

void CitesteObiecte()
{
    fin >> n >> G;
    for (int i = 1; i <= n; ++i)
        fin >> g[i] >> v[i];
}

void Rucsac()  // Dinamica O(n * G)
{
    // cazuri de baza
    for (int j = 0; j <= G; ++j)
        c[j] = -Inf;

    c[0] = 0;

    for (int i = 1; i <= n; ++i)    // pentru fiecare obiect
        for (int j = 0; j <= G - g[i]; ++j)
            if (c[j] != -Inf &&     // daca greutatea j a fost obtinuta in rucsac
                c[j + g[i]] < c[j] + v[i])
            {
                c[j + g[i]] = c[j] + v[i];
                t[j + g[i]] = i;
                if (c[j + g[i]] > vmax)
                {
                    vmax = c[j + g[i]];
                    gr_ob = j + g[i];
                }
            }
}

void Obiecte(int gr)
{
    if (gr == 0) return;
    Obiecte(gr - g[t[gr]]);
    fout << "Obiectul " << t[gr] << " de greutate "
         << g[t[gr]] << " si valoare " << v[t[gr]] << '\n';
}