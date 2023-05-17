#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");

struct Nod {
    int val;
    int st, dr;
};

const int N = 1001;
Nod arb[N];
int niv[N];
int t[N];
int root;
int n;

void PreOrdine(int x, int nv);
int main()
{
    fin >> n;
    int val, st, dr;
    for (int i = 1; i <= n; ++i)
    {
        fin >> val >> st >> dr;

        arb[i] = {val, st, dr};

        if (st) t[st] = i;
        if (dr) t[dr] = i;
    }

    for (int i = 1; i <= n; ++i)
        if (t[i] == 0)
        {
            root = i;
            break;
        }

    PreOrdine(root, 1);

    int nr_nivele = 0;
    int frecv[N] {0};

    for (int i = 1; i <= n; ++i)
    {
        nr_nivele = max(nr_nivele, niv[i]);
        frecv[niv[i]]++;
    }

    fout << nr_nivele << '\n';
    for (int i = 1; i <= nr_nivele; ++i)
        fout << frecv[i] << ' ';

    return 0;
}

void PreOrdine(int x, int nv)
{
    if (!x) return;
    niv[x] = nv;

    PreOrdine(arb[x].st, nv + 1);
    PreOrdine(arb[x].dr, nv + 1);
}