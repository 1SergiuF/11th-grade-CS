#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;

ifstream fin("aemi.in");
ofstream fout("aemi.out");

#define DIM 100010
#define INF INT_MAX

int A[4 * DIM];
int n, m, t, a, b, vmin;

void Build(int nod, int st, int dr);
void Update(int nod, int st, int dr, int poz, int val);
void Query(int nod, int st, int dr, int a, int b);

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
            Update(1, 1, n, a, b);
    }
    
    return 0;
}

void Build(int nod, int st, int dr)
{
    if (st == dr)
    {
        fin >> A[nod];
        return;
    }

    int mid = (st + dr) / 2;
    Build(2 * nod, st, mid);
    Build(2 * nod + 1, mid + 1, dr);
    A[nod] = min(A[2 * nod], A[2 * nod + 1]);
}

void Update(int nod, int st, int dr, int poz, int val)
{
    if (st == dr)
    {
        A[nod] = val;
        return;
    }

    int mid = (st + dr) / 2;

    if (poz <= mid) Update(2 * nod, st, mid, poz, val);
    if (poz > mid) Update(2 * nod + 1, mid + 1, dr, poz, val);
    A[nod] = min(A[2 * nod], A[2 * nod + 1]);
}

void Query(int nod, int st, int dr, int a, int b)
{
    if (a <= st && dr <= b)
    {
        vmin = min(vmin, A[nod]);
        return;
    }

    int mid = (st + dr) / 2;

    if (a <= mid) Query(2 * nod, st, mid, a, b);
    if (b > mid) Query(2 * nod + 1, mid + 1, dr, a, b);
}