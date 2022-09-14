/*
    Generarea Permutarilor unei multimi
    in ordine crescator lexicografica
    Complexitate : O(n!)

    A = {1,   2,   3,   4}  n = 4

         1    2    3    4  S
         1    2    4    3  S
         1    3    2    4  S
         1    3    4    2  S
         ........
         4    3    2    1  S
       x[1] x[2] x[3] x[4]
       P(1) P(2) P(3) P(4) P(5)

         7    3         9       1
       x[1] x[2] ... x[k - 1] x[k]
       P(1) P(2) ....P(k - 1) P(k)
*/

#include <fstream>
using namespace std;

ifstream fin("perm.in");
ofstream fout("perm.out");

int x[15]; // x[k] = i (al k lea elem al permutarii sa fie i)
int n;     // nr de elem ale multimii
int nrsol;

void Perm(int k); // k = pozitia curenta in sir
bool Ok(int k);   // functie de validare (de continuare)
void ScrieSol();

int main()
{
    fin >> n;
    Perm(1);

    fout << nrsol << " solutii !";
}

void Perm(int k)
{
    if (k > n)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (Ok(k))
            Perm(k + 1);
    }
}

bool Ok(int k)
{
    for (int i = 1; i < k; ++i)
        if (x[i] == x[k])
            return false;

    return true;
}

void ScrieSol()
{
    ++nrsol;
    for (int i = 1; i <= n; ++i)
        fout << x[i] << ' ';
    fout << '\n';
}