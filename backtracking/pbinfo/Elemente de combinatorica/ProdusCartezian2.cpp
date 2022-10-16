#include <fstream>
using namespace std;

ifstream fin("produscartezian2.in");
ofstream fout("produscartezian2.out");

int n;
int x[10];
int card[10];

void Cartez(int k);
void ScrieSol(int k);

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> card[i];

    Cartez(1);
}

void Cartez(int k)
{
    if (k > n)
    {
        ScrieSol(n);
        return;
    }

    for (int i = 1; i <= card[k]; ++i)
    {
        x[k] = i;
        Cartez(k + 1);
    }
}

void ScrieSol(int k)
{
    for (int i = 1; i <= k; ++i)
        fout << x[i] << ' ';
    fout << '\n';
}