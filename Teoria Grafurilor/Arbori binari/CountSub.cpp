#include <fstream>
using namespace std;

ifstream fin("countsub.in");
ofstream fout("countsub.out");

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
int NrNoduriSubarb(int nod);

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
        fout << NrNoduriSubarb(x) << '\n';
    }
}

int NrNoduriSubarb(int nod)
{
    if (!nod) return 0;

    return 1 + NrNoduriSubarb(arb[nod].st) + NrNoduriSubarb(arb[nod].dr);
}