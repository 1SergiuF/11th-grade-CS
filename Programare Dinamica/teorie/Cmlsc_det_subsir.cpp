#include <fstream>
using namespace std;

ifstream fin("cmlsc_subsir.in");
ofstream fout("cmlsc_subsir.out");

const int N = 1001;
int n, a[N];
int L[N];
int t[N];
int Lmax;
int k;

void CitesteSir();
void Cmlsc();
void Subsir(int i);

int main()
{
    CitesteSir();
    Cmlsc();
    fout << Lmax << '\n';
    Subsir(k);

    return 0;
}

void CitesteSir()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
}

void Cmlsc()
{
    for (int i = 1; i <= n; ++i)
    {
        L[i] = 1;
        for (int j = 1; j < i; ++j)
            if (L[j] + 1 > L[i] && a[j] < a[i])
            {
                L[i] = L[j] + 1;
                t[i] = j;
            }

        if (Lmax < L[i])
        {
            Lmax = L[i];
            k = i;
        }
    }
}

void Subsir(int i)
{
    if (i == 0) return;
    Subsir(t[i]);
    fout << a[i] << ' ';
}