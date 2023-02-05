#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define Dim 5000001
int A[4 * Dim];
int n, q, op, x, y;
char ch;
string str;

void Build(int nod, int st, int dr);
void Update(int nod, int st, int dr, int poz, int val);
int Query(int nod, int st, int dr, int l, int r);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> str >> q;
    Build(1, 1, n);

    for (int i = 1; i <= q; ++i)
    {
        cin >> op >> x;
        if (op == 1)
        {
            cin >> ch;
            Update(1, 1, n, x, 1 << (ch - 'a'));
        }

        else
        {
            cin >> y;
            cout << __builtin_popcount(Query(1, 1, n, x, y)) << '\n';
        }
    }
    
    return 0;
}

void Build(int nod, int st, int dr)
{
    if (st == dr)
    {
        A[nod] = 1 << (str[st - 1] - 'a');
        return;
    }

    int mid = (st + dr) / 2;
    Build(2 * nod, st, mid);
    Build(2 * nod + 1, mid + 1, dr);

    A[nod] = (A[2 * nod] | A[2 * nod + 1]);
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
    else
        Update(2 * nod + 1, mid + 1, dr, poz, val);

    A[nod] = (A[2 * nod] | A[2 * nod + 1]);
}

int Query(int nod, int st, int dr, int l, int r)
{
    if (l <= st && dr <= r)
        return A[nod];

    int mid = (st + dr) / 2, r1 = 0, r2 = 0;

    if (l <= mid)
        r1 = Query(2 * nod, st, mid, l, r);
    if (mid < r)
        r2 = Query(2 * nod + 1, mid + 1, dr, l, r);

    return (r1 | r2);
}