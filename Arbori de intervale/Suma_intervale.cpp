#include <iostream>
#include <vector>
using namespace std;

#define Dim 100010

int A[4 * Dim];
int n, m, op, a, b, sum, cnt, c[Dim];

void Build(int nod, int st, int dr);
void Update(int nod, int st, int dr, int poz, int val);
void Query(int nod, int st, int dr, int a, int b);

vector<int> sume;
int main()
{
    cin >> n >> m;
    Build(1, 1, n);

    for (int i = 1; i <= m; ++i)
    {
        cin >> op >> a >> b;
        if (op == 1)
            Update(1, 1, n, a, b);
        else if (op == 2)
        {
            sum = 0;
            Query(1, 1, n, a, b);
            c[++cnt] = sum;
        }
    }

    for (int i = 1; i <= cnt; ++i)
        cout << c[i] << '\n';

    return 0;
}

void Build(int nod, int st, int dr)
{
    if (st == dr)
    {
        cin >> A[nod];
        return;
    }

    int mid = (st + dr) / 2;
    Build(2 * nod, st, mid);
    Build(2 * nod + 1, mid + 1, dr);
    A[nod] = A[2 * nod] + A[2 * nod + 1];
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

    A[nod] = A[2 * nod] + A[2 * nod + 1];
}

void Query(int nod, int st, int dr, int a, int b)
{
    if (a <= st && dr <= b)
    {
        sum += A[nod];
        return;
    }

    int mid = (st + dr) / 2;
    if (a <= mid)
        Query(2 * nod, st, mid, a, b);
    if (b > mid)
        Query(2 * nod + 1, mid + 1, dr, a, b);
}