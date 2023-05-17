#include <fstream>
using namespace std;

ifstream fin("countprimsub.in");
ofstream fout("countprimsub.out");

struct Nod {
    int val;
    int st, dr;
};

#define N 1001
int n, k;
Nod arb[N];
int val;
int st, dr;

void CitesteArbore();
int NrNoduriSubarbPrime(int nod);
bool EstePrim(int x);

int main()
{
    CitesteArbore();
    return 0;
}

void CitesteArbore()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> val >> st >> dr;
        arb[i].val = val;
        arb[i].st = st;
        arb[i].dr = dr;
    }

    int x;
    fin >> k;
    for (int i = 1; i <= k; ++i)
    {
        fin >> x;
        fout << NrNoduriSubarbPrime(x) << '\n';
    }
}

int NrNoduriSubarbPrime(int nod)
{
    if (!nod) return 0;

    return EstePrim(arb[nod].val) 
        ? 1 + NrNoduriSubarbPrime(arb[nod].st) + NrNoduriSubarbPrime(arb[nod].dr)
        : NrNoduriSubarbPrime(arb[nod].st) + NrNoduriSubarbPrime(arb[nod].dr);
}

bool EstePrim(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;

    return true;
}