/*
   Generarea Aranjamentelor de n luate cate k
   Fie A = {1, 2, 3, ..., n} o multime.
   Atunci Aranj(n, k) este numarul de posibilitati
   de a alege k elemente din multimea A,
   a.i. ORDINEA CONTEAZA.

   Aranj(n, k) = n! / (n - k)!
*/

#include <fstream>
#include <string>
using namespace std;

ifstream fin("aranj.in");
ofstream fout("aranj.out");

int n, p; // generam Aranj(n, p)
int x[15];
bool s[15]; // s[i] = true daca i a fost deja plasat in sirul x[]
int nrsol;

void Aranj(int k);
void ScrieSol();

int main()
{
    fin >> n >> p;
    Aranj(1);

    string result = (nrsol) ? to_string(nrsol).append(" solutii") : "nu exista solutii";
    fout << result;
    return 0;
}

void Aranj(int k)
{
    if (k > p)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (!s[i])
        {
            s[i] = true;
            Aranj(k + 1);
            s[i] = false;
        }
    }
}

void ScrieSol()
{
    ++nrsol;
    for (int i = 1; i <= p; ++i)
        fout << x[i] << ' ';
    fout << '\n';
}