#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;

ifstream fin("aimi.in");
ofstream fout("aimi.out");

#define Dim 100010
#define INF INT_MAX

struct nod {
    int value;
    int lazy;
};

nod A[4 * Dim];
int n, m, t, a, b, vmin, x;

void Build(int nod, int st, int dr);
void Query(int nod, int st, int dr, int a, int b);
void Update(int nod, int st, int dr, int a, int b, int x);

int main()
{
    fin >> n;
    Build(1, 1, n);

    fin >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> t >> a >> b;
        if (t == 1)
        {
            vmin = INF;
            Query(1, 1, n, a, b);
            fout << vmin << '\n';
        }

        else
        {
            fin >> x;
            Update(1, 1, n, a, b, x);
        }
    }
    
    return 0;
}

void Build(int nod, int st, int dr)
{
    if (st == dr)
    {
        fin >> A[nod].value;
        return;
    }

    int mid = (st + dr) / 2;
    Build(2 * nod, st, mid);
    Build(2 * nod + 1, mid + 1, dr);
    A[nod].value = min(A[2 * nod].value, A[2 * nod + 1].value);
}

void Query(int nod, int st, int dr, int a, int b)
{
    if (a <= st && dr <= b)
    {
        vmin = min(vmin, A[nod].value);
        return;
    }

    if (A[nod].lazy == 1)
    {
        A[2 * nod].value = A[nod].value;
        A[2 * nod].lazy = 1;
        A[2 * nod + 1].value = A[nod].value;
        A[2 * nod + 1].lazy = 1;
        A[nod].lazy = 0;
    }

    int mid = (st + dr) / 2;
    if (a <= mid)
        Query(2 * nod, st, mid, a, b);
    if (b > mid)
        Query(2 * nod + 1, mid + 1, dr, a, b);

    A[nod].value = min(A[2 * nod].value, A[2 * nod + 1].value);
}

void Update(int nod, int st, int dr, int a, int b, int x)
{
    if (a <= st && dr <= b)
    {
        A[nod].value = x;
        A[nod].lazy = 1;
        return;
    }

    if (A[nod].lazy == 1)
    {
        A[2 * nod].value = A[nod].value;
        A[2 * nod].lazy = 1;
        A[2 * nod + 1].value = A[nod].value;
        A[2 * nod + 1].lazy = 1;
        A[nod].lazy = 0;
    }

    int mid = (st + dr) / 2;
    if (a <= mid)
        Update(2 * nod, st, mid, a, b, x);
    if (b > mid)
        Update(2 * nod + 1, mid + 1, dr, a, b, x);

    A[nod].value = min(A[2 * nod].value, A[2 * nod + 1].value);
}