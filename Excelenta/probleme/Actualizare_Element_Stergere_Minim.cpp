#include <fstream>
using namespace std;

ifstream fin("aesm.in");
ofstream fout("aesm.out");

#define DIM 100010
#define INF 2000000001

struct nod {
    int minim;
    int poz;
    int cnt;
};

nod A[4 * DIM];
int n, m, x, p, t;

void Build(int nod, int st, int dr);
void Update(int nod, int st, int dr, int poz, int x);
int GetPoz(int nod, int st, int dr, int p);

int main()
{
    fin >> n;
    Build(1, 1, n);

    fin >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> t;
        if (t == 1)
        {
            fout << A[1].minim << '\n';
            Update(1, 1, n, A[1].poz, INF);
        }

        else
        {
            fin >> p >> x;
            t = GetPoz(1, 1, n, p);
            Update(1, 1, n, t, x);
        }
    }

    return 0;
}

void Build(int nod, int st, int dr)
{
    if (st == dr)
    {
        fin >> A[nod].minim;
        A[nod].poz = st;
        A[nod].cnt = 1;
        return;
    }

    int mid = (st + dr) / 2;
    Build(2 * nod, st, mid);
    Build(2 * nod + 1, mid + 1, dr);

    A[nod].minim = A[2 * nod].minim;
    A[nod].poz = A[2 * nod].poz;

    if (A[2 * nod + 1].minim < A[nod].minim)
    {
        A[nod].minim = A[2 * nod + 1].minim;
        A[nod].poz = A[2 * nod + 1].poz;
    }

    A[nod].cnt = A[2 * nod].cnt + A[2 * nod + 1].cnt;
}

void Update(int nod, int st, int dr, int poz, int x)
{
    if (st == dr)
    {
        A[nod].minim = x;
        A[nod].poz = st;
        if (x == INF)
            A[nod].cnt = 0;
        else
            A[nod].cnt = 1;

        return;
    }

    int mid = (st + dr) / 2;
    if (poz <= mid)
        Update(2 * nod, st, mid, poz, x);
    if (poz > mid)
        Update(2 * nod + 1, mid + 1, dr, poz, x);

    A[nod].minim = A[2 * nod].minim;
    A[nod].poz = A[2 * nod].poz;

    if (A[2 * nod + 1].minim < A[nod].minim)
    {
        A[nod].minim = A[2 * nod + 1].minim;
        A[nod].poz = A[2 * nod + 1].poz;
    }

    A[nod].cnt = A[2 * nod].cnt + A[2 * nod + 1].cnt;
}

int GetPoz(int nod, int st, int dr, int p)
{
    if (st == dr) return st;

    int mid = (st + dr) / 2;

    if (A[2 * nod].cnt >= p)
        return GetPoz(2 * nod, st, mid, p);

    return GetPoz(2 * nod + 1, mid + 1, dr, p - A[2 * nod].cnt);
}