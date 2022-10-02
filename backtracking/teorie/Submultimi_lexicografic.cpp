#include <fstream>
using namespace std;

ifstream fin("submultimi2.in");
ofstream fout("submultimi2.out");

int n, p;
int x[15];
int nrsol;

void Subm(int k);
void ScrieSol(int k);

int main()
{
    fin >> n >> p;
    fout << "{ }\n";
    ++nrsol;
    Subm(1);
    fout << nrsol << " solutii" ;
    return 0;
}

void Subm(int k)
{
    if (k > n) return;

    for (int i = x[k - 1] + 1; i <= n; ++i)
    {
        x[k] = i;
        ScrieSol(k);
        Subm(k + 1);
    }
}

void ScrieSol(int k)
{
    ++nrsol;
    fout << "{ ";
    for (int i = 1; i <= k; ++i)
        fout << x[i] << ' ';
    
    fout << "}";
    fout << '\n';
}