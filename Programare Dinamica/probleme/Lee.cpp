#include <iostream>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define __Lee Lee(PQ.top().first, PQ.top().second, L)
#define __qpop (PQ.pop())
#define iv (i + di[d])
#define jv (j + dj[d])
typedef pair<int, int> pi;

struct Cel {
    int i, j;
};

const int N = 104;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int Inf = 0x3f3f3f3f;

bool a[N][N];
int L[N][N];

int n, x1, y1, x2, y2, x3, y3;
void CitesteDate();
void Lee(int ip, int jp, int L[][N]);
bool Ok(int i, int j);

int main()
{
    CitesteDate();

    priority_queue<pi> PQ;
    PQ.push(make_pair(x1, y1));
    PQ.push(make_pair(x2, y2));
    PQ.push(make_pair(x3, y3));

    Lee(1, 1, L);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << L[i][j] << ' ';
        cout << '\n';
    }
    __Lee;
    int q1 = L[n][n];

    __qpop;
    __Lee;
    int q2 = L[n][n] - q1;

    __qpop;
    __Lee;
    int q3 = L[n][n] - q2;

    Lee(1, 1, L);
    int q4 = L[PQ.top().first][PQ.top().second];

    cout << q1 + q2 + q3 + q4;

}

void CitesteDate()
{
    cin >> n;
    FOR(i, n)
        FOR(j, n)
            cin >> a[i][j];

    cin >> x1 >> y1
        >> x2 >> y2
        >> x3 >> y3;
}

void Lee(int ip, int jp, int L[][N])
{
    Cel Q[N * N];
    int u = -1, p = 0;

    FOR(i, n)
        FOR(j, n)
            L[i][j] = Inf;

    L[ip][jp] = 0;
    Q[++u] = {ip, jp};

    while (p <= u)
    {
        int i = Q[p].i;
        int j = Q[p].j;
        p++;

        for (int d = 0; d < 4; ++d)
        {
            if (Ok(iv, jv) && L[iv][jv] > L[i][j] + 1)
            {
                L[iv][jv] = L[i][j] + 1;
                Q[++u] = {iv, jv};
            }
        }
    }
}

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n)
        return false;

    if (a[i][j])
        return false;

    return true;
}