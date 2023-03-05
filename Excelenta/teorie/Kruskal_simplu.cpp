/* 
    Algoritmul lui Kruskal
    Det arborelui partial de cost minim intr-un graf
    Minimum spanning tree (arborele minim de acoperire)
*/

#include <fstream>
using namespace std;

ifstream fin("kruskal2.in");
ofstream fout("kruskal2.out");

#define MAX 101

struct Muchie {
    int v1, v2;
    int cost;
};

Muchie g[MAX];  // memoreaza graful ca un sir de muchiii
Muchie arb[MAX];    // APM
int comp[MAX];  // sir caracteristic
                // comp[i] = j  nodul i se afla in comp conexa j)
int cost_min;   // costul APM (arb part de cost min)
int n, m;   // nr noduri nr muchii ale grafului

void CitesteGraf();
void Kruskal();
void Afiseaza();
void Sorteaza();

int main()
{
    CitesteGraf();
    Kruskal();
    Afiseaza();
    return 0;
}

void CitesteGraf()
{
    fin >> n;
    m = 0;
    int v1, v2, cost;
    while (fin >> v1 >> v2 >> cost)
    {
        m++;
        g[m].v1   = v1;
        g[m].v2   = v2;
        g[m].cost = cost;
    }
}

void Sorteaza()     // O(m^2)
{
    for (int i = 1; i < m; ++i)
        for (int j = i + 1; j <= m; ++j)
            if (g[j].cost < g[i].cost)
            {
                Muchie aux = g[i];
                g[i] = g[j];
                g[j] = aux;
            }
}

void Kruskal()
{
    Sorteaza(); // O(m^2) O(m * log2(m))
    int i, j;
    int k = 0;  // nr muchii in APM
    int c1, c2; // componnetele conexe ale varfurilor muchiei
    for (i = 1; i <= n; ++i)    // O(n)
        comp[i] = i;

    for (i = 1; i <= m; ++i)                // O(M * N)
        if (comp[g[i].v1] != comp[g[i].v2]) // O(1) daca nu formeaza ciclu  (FIND)
        {
            cost_min += g[i].cost;
            arb[++k] = g[i];    // adaug muchia i in APM
            c1 = comp[g[i].v1]; // O(1)
            c2 = comp[g[i].v2];
            for (j = 1; j <= n; ++j)    // O(n)    UNION
                if (comp[j] == c2)
                    comp[j] = c1;
            if (k == n - 1) break;
        }
}

void Afiseaza()
{
    fout << "Costul APM este: " << cost_min << '\n';
    for (int i = 1; i < n; ++i)
        fout << arb[i].v1   << ' '
             << arb[i].v2   << ' '
             << arb[i].cost << '\n';
}