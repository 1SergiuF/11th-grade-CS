/*
    Problema Bancnotelor
    Sa se plateasca o suma S cu n tipuri de bancnote,
    de valori v[1], v[2], ..., v[n], stiind ca:

    a) exista oricate bancnote din fiecare tip
    b) nu este obligatorie sa fie utilizate toate tipurile de bancnote

    s = x[1]*v[1] + ... * x[k-1]*v[k-1]

    Suma pana la poz k, este:

    S = s + x[k] * v[k]

*/

#include <fstream>
using namespace std;

ifstream fin("bancnote.in");
ofstream fout("bancnote.out");

int n;      // nr de tipuri de bancnote
int S;      // Suma care trebuie platita
int v[20];  // valorile bancnotelor
int x[20];  // x[k] numarul de bancnote de valoare v[k], care se platesc
int nrsol;

void Bancnote(int k, int s);
void ScrieSol(int k);
void CitesteDate();

int main()
{
    CitesteDate();
    Bancnote(1, 0);
    fout << nrsol << " solutii";

    return 0;
}

void Bancnote(int k, int s)   // s = x[1]* v[1] + ... + x[k-1]*v[k-1]
{
    if (s == S)
    {
        ScrieSol(k - 1);
        return;
    }

    if (k > n) return;

    for (int i = 0; s + i * v[k] <= S; ++i)
    {
        x[k] = i;
        Bancnote(k + 1, s + i * v[k]);
    }
}

void ScrieSol(int k)
{
    ++nrsol;
    fout << S << " = ";
    for (int i = 1; i < k; ++i)
        if (x[i])
            fout << x[i] << " * " << v[i] << " + ";
    
    fout << x[k] << " * " << v[k] << '\n';
}

void CitesteDate()
{
    fin >> n >> S;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
}