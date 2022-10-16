/*
    Partitiile unui numar
    Ex:
    n = 4
    4 = 1 + 1 + 1 + 1
    4 = 1 + 1 + 2
    4 = 1 + 3
    4 = 2 + 2
    4 = 4
*/

#include <fstream>
using namespace std;

ifstream fin("partitiinumar.in");
ofstream fout("partitiinumar.out");

int x[50]; // x[k] este al k-lea termen al partitiei curente
int n;     // numarul care trebuie partitionat

void PartNr(int k, int s); // s = x[1] + x[2] + ... + x[k - 1]
void ScrieSol(int k);

int main()
{
    fin >> n;
    PartNr(1, 0);
    return 0;
}

void PartNr(int k, int s)
{
    if (s == n)
    {   
        ScrieSol(k - 1);
        return;
    }

    for (int i = k == 1 ? 1 : x[k - 1]; s + i <= n; ++i)
    {
        x[k] = i;
        PartNr(k + 1, s + i);
    }
}

void ScrieSol(int k)
{
    fout << n << " = ";
    
    for (int i = 1; i < k; ++i)
        fout << x[i] << " + ";
    fout << x[k] << '\n';
}