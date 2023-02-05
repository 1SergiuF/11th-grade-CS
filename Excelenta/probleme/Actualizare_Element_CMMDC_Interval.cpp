#include <fstream>
#include <climits>
using namespace std;

ifstream fin("aecmmdci.in");
ofstream fout("aecmmdci.out");

#define INF INT_MAX
#define DIM 100010

int A[4 * DIM];
int n, m, t, a, b, cmd;

int Cmmdc(int a, int b);
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
            cmd = INF;
            Query(1, 1, n, a, b);
            fout << cmd << '\n';
        }

        else
            Update(1, 1, n, a, b);
    }

    return 0;
}

int Cmmdc(int a, int b)
{
    int r;
    while (b) 
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
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
    A[nod] = Cmmdc(A[2 * nod], A[2 * nod + 1]);
}

void Update(int nod, int st, int dr, int poz, int val)
{
    if (st == dr)
    {
        A[nod] = val;
        return;
    }

    int mid = (st + dr) / 2;

    if (poz <= mid)
        Update(2 * nod, st, mid, poz, val);
    if (poz > mid)
        Update(2 * nod + 1, mid + 1, dr, poz, val);

    A[nod] = Cmmdc(A[2 * nod], A[2 * nod + 1]);
}

void Query(int nod, int st, int dr, int a, int b)
{
    if (a <= st && dr <= b)
    {
        if (cmd == INF)
            cmd = A[nod];
        else
            cmd = Cmmdc(cmd, A[nod]);

        return;
    }

    int mid = (st + dr) / 2;

    if (a <= mid)
        Query(2 * nod, st, mid, a, b);
    if (b > mid)
        Query(2 * nod + 1, mid + 1, dr, a, b);
}